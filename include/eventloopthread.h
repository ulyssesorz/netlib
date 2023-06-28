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

//将loop和thread结合起来
class EventLoopThread : NonCopyable
{
public:
    EventLoopThread(const ThreadInitCallback& callback = ThreadInitCallback(), const string& name = "");
    ~EventLoopThread();

    EventLoop* startLoop();

private:
    //给thread绑定的方法
    void threadFunction();

private:
    //包含的loop
    EventLoop *loop_;
    bool exiting_;

    //包含的thread
    Thread thread_;

    mutex thread_mutex_;
    condition_variable condition_;

    ThreadInitCallback callback_;
};