#pragma once
#include<string>
#include<vector>
#include<memory>
#include<functional>
#include"noncopyable.h"

class EventLoop;
class EventLoopThread;

using namespace std;

using ThreadInitCallback = function<void(EventLoop*)>;

class EventLoopThreadPool : NonCopyable
{
public:
    EventLoopThreadPool(EventLoop *baseloop, const string &name);
    ~EventLoopThreadPool();

    void setThreadNum(int thread_num) { thread_num_ = thread_num; }

    void start(const ThreadInitCallback& callback = ThreadInitCallback());

    EventLoop *getNextEventLoop();

    vector<EventLoop *> getAllLoops();

    bool getStarted() const { return started_; }
    string getName() const { return name_; }

private:
    EventLoop *baseloop_;
    string name_;

    bool started_;
    int thread_num_;
    int next_;
    //子loop的集合
    vector<unique_ptr<EventLoopThread>> threads_; 
    vector<EventLoop*> loops_;                   
};