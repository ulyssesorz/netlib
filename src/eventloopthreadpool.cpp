#include"eventloopthreadpool.h"
#include"eventloopthread.h"

EventLoopThreadPool::EventLoopThreadPool(EventLoop* baseloop, const string& name) : 
    baseloop_(baseloop), name_(name), started_(false), thread_num_(0), next_(0)
{ 
}

EventLoopThreadPool::~EventLoopThreadPool()
{
}

void EventLoopThreadPool::start(const ThreadInitCallback& callback)
{
    started_ = true;
    //只有一个主loop
    if(thread_num_ == 0)
    {
        callback(baseloop_);
    }
    else
    {
        for(int i = 0; i < thread_num_; ++i)
        {
            char buf[name_.size() + 32] = {0};
            snprintf(buf, sizeof(buf), "%s %d", name_.c_str(), i);
            EventLoopThread* t = new EventLoopThread(callback, buf);
            threads_.push_back(unique_ptr<EventLoopThread>(t));
            loops_.push_back(t->startLoop());
        }
    }
}

EventLoop* EventLoopThreadPool::getNextEventLoop()
{
    EventLoop* loop = baseloop_;
    if(!loops_.empty())
    {
        loop = loops_[next_++];
        if(next_ == loops_.size())
        {
            next_ = 0;
        }
    }
    return loop;
}

vector<EventLoop*> EventLoopThreadPool::getAllLoops()
{
    return loops_.empty() ? vector<EventLoop*>(1, baseloop_) : loops_;
}