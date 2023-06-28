#include<unistd.h>
#include<fcntl.h>
#include<sys/eventfd.h>
#include"eventloop.h"
#include"logger.h"

//每个线程独享loop
__thread EventLoop* t_loop_in_thisThread = nullptr;

const int kPollTimeout = 10000;

//创建主loop和子loop通信的fds
static int createEventFd()
{
    int event_fd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if(event_fd < 0)
    {
        LOG_FATAL("eventfd error: %d\n", errno);
    }
    return event_fd;
}

EventLoop::EventLoop() : looping_(false), quit_(false), calling_pending_functors_(false),
    threadId_(Current_thread::tid()), poller_(Poller::newDefaultPoller(this)),
    wakeup_fd_(createEventFd()), wakeup_channel_(new Channel(this, wakeup_fd_))
{
    LOG_DEBUG("EventLoop created %p in thread %d\n", this, threadId_);
    //判断有没有被其他线程重入
    if(t_loop_in_thisThread != nullptr)
    {
        LOG_FATAL("Another EventLoop %p exists int this thread %d\n", this, threadId_);
    }
    else
    {
        t_loop_in_thisThread = this;
    }
    //绑定子loop的回调方法，handleRead准备接受唤醒的命令，同时允许读
    wakeup_channel_->setReadCallback(bind(&EventLoop::handleRead, this));
    wakeup_channel_->enableReading();
}

EventLoop::~EventLoop()
{
    wakeup_channel_->disenableAll();
    wakeup_channel_->remove();
    close(wakeup_fd_);
    t_loop_in_thisThread = nullptr;
}

void EventLoop::loop()
{
    looping_ = true;
    quit_ = false;
    LOG_INFO("EventLoop %p start looping\n", this);

    while(!quit_)
    {
        active_channels_.clear();
        //poll监听端口，收集活跃channel
        poll_return_time_ = poller_->poll(kPollTimeout, &active_channels_);
        //调用活跃channel的回调方法
        for(auto channel : active_channels_)
        {
            channel->handleEvent(poll_return_time_);
        }
        //执行上述回调过程中队列等待了其他回调，现在开始执行
        doPendingFunctors();
    }
    LOG_INFO("EventLoop %p stop looping", this);
    looping_ = false;
}

void EventLoop::quit()
{
    quit_ = true;
    //当前线程不是io线程，或者是io线程但正在执行其他回调，就唤醒io线程
    if(!isInLoopthread() || calling_pending_functors_)
    {
        wakeup();
    }
}

void EventLoop::wakeup()
{
    uint64_t msg = 1;
    //向子loop写数据唤醒channel
    ssize_t n = write(wakeup_fd_, &msg, sizeof(msg));
    if(n != sizeof(msg))
    {
        LOG_ERROR("EventLoop::wakeup() writes %lu bytes instead of 8\n", n);
    }
}

void EventLoop::runInLoop(Functor callback)
{
    //loop和线程匹配（是当前loop在执行runInLoop方法），执行回调
    if(isInLoopthread())
    {
        callback();
    }
    //其他loop将callback绑定到本loop的runInLoop
    //本loop还没被调度，callback先排队等待
    else
    {
        queueInLoop(callback);
    }
}

void EventLoop::queueInLoop(Functor callback)
{
    //放入等待队列中
    {
        lock_guard<mutex> locker(functor_mutex_);
        pending_functors_.emplace_back(callback);
    }
    //当前线程不是io线程，或者是io线程但正在执行其他回调，就唤醒它
    if(!isInLoopthread() || calling_pending_functors_)
    {
        wakeup();
    }
}

void EventLoop::updateChannel(Channel* channel)
{
    poller_->updateChannel(channel);
}

void EventLoop::removeChannel(Channel* channel)
{
    poller_->removeChannel(channel);
}

bool EventLoop::hasChannel(Channel* channel)
{
    return poller_->hasChannel(channel);
}

void EventLoop::handleRead()
{
    uint64_t msg = 1;
    ssize_t n = read(wakeup_fd_, &msg, sizeof(int));
    if(n != sizeof(msg))
    {
        LOG_ERROR("EventLoop::handleRead() read %lu bytes instead of 8\n", n);
    }
}

void EventLoop::doPendingFunctors()
{
    vector<Functor> functors;
    calling_pending_functors_ = true;
    //用functors获取当前的pending_functors_，相当于做一个快照，后续for遍历就不用加锁了
    //利用额外空间，大量减少锁持有的时间
    {
        lock_guard<mutex> locker(functor_mutex_);
        swap(functors, pending_functors_);
    }
    for(auto functor : functors)
    {
        functor();
    }
    calling_pending_functors_ = false;
}