#pragma once
#include<functional>
#include<string>
#include<mutex>
#include<condition_variable>
#include"noncopyable.h"
#include"thread.h"

using namespace std;

class EventLoop;

using ThreadInitCallback = function<void(EventLoop*)>;

class EventLoopThread : NonCopyable
{
public:
    EventLoopThread(const ThreadInitCallback &callback = ThreadInitCallback(), const string& name = string());
    ~EventLoopThread();

    EventLoop* startLoop();

private:
    void threadFunction();

private:
    EventLoop *loop_;
    bool exiting_;

    Thread thread_;

    mutex thread_mutex_;
    condition_variable condition_;

    ThreadInitCallback callback_;
};