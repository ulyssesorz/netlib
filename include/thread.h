#pragma once

#include<functional>
#include<thread>
#include<memory>
#include<unistd.h>
#include<atomic>
#include"noncopyable.h"
using namespace std;

using ThreadFunc = function<void()>;

class Thread : public NonCopyable
{
public:
    explicit Thread(ThreadFunc func, const string& name = "");
    ~Thread();

    void start();
    void join();

    bool isStarted() const {return started_;}
    pid_t getTid() const {return tid_;}
    const string& getName() const {return name_;}
    static int getThreadNum() {return thread_num_;}

private:
    void setDefaultName();
    //是否开启和可结合
    bool started_;
    bool joined_;
    //智能指针管理
    shared_ptr<thread> thread_;
    //线程的一些信息
    pid_t tid_;
    ThreadFunc function_;
    string name_;
    static atomic<int> thread_num_;
};