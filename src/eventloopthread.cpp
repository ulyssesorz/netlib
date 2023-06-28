#include<memory>
#include"eventloopthread.h"
#include"eventloop.h"

EventLoopThread::EventLoopThread(const ThreadInitCallback& callback, const string& name)
    :loop_(nullptr), exiting_(false), thread_(bind(&EventLoopThread::threadFunction, this), name),
    callback_(callback)
{
}

EventLoopThread::~EventLoopThread()
{
    exiting_ = true;
    if(loop_ != nullptr)
    {
        loop_->quit();
        thread_.join();
    }
}

//开启线程，并通过条件变量阻塞进程直到获得loop
EventLoop* EventLoopThread::startLoop()
{
    thread_.start();
    EventLoop* loop = nullptr;
    {
        unique_lock<mutex> locker(thread_mutex_);
        while(loop_ == nullptr)
        {
            condition_.wait(locker);
        }
        loop = loop_;
    }
    return loop;
}

//线程的任务
void EventLoopThread::threadFunction()
{
    //线程创建一个loop
    EventLoop loop;
    if(callback_)
    {
        callback_(&loop);
    }
    {
        //拿到loop后唤醒startLoop()
        unique_lock<mutex> locker(thread_mutex_);
        loop_ = &loop;
        condition_.notify_one();
    }
    //开启loop
    loop.loop();
    //关闭loop
    lock_guard<mutex> locker(thread_mutex_);
    loop_ = nullptr;
}