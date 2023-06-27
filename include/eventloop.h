#pragma once

#include<vector>
#include<atomic>
#include<functional>
#include<memory>
#include<mutex>
#include"noncopyable.h"
#include "timestamp.h"
#include "currentthread.h"
#include "poller.h"
#include "channel.h"

using namespace std;

using Functor = function<void()>;
using ChannelList = vector<Channel*>;

class EventLoop : NonCopyable
{
public:
    EventLoop();
    ~EventLoop();

    //开启循环
    void loop();
    //退出循环
    void quit();

    TimeStamp getPollReturnTime() const { return poll_return_time_; }

    //在当前loop执行回调
    void runInLoop(Functor callback);
    //把回调放入队列，唤醒loop执行
    void queueInLoop(Functor callback);

    //唤醒loop
    void wakeup();

    //poller的方法
    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    bool hasChannel(Channel* channel);

    //当前loop是否在自己的线程里
    bool isInLoopthread() const { return threadId_ == Current_thread::tid(); }

private:
    //接收wakeup发送的数据
    void handleRead();         
    //执行等待队列中的回调
    void doPendingFunctors(); 

private:
    atomic<bool> looping_;
    atomic<bool> quit_; 

    const pid_t threadId_;       
    TimeStamp poll_return_time_; 
    //多reactor，每个loop有自己的多路复用器
    unique_ptr<Poller> poller_;

    //主loop要唤醒子loop的fd和channel
    int wakeup_fd_;                      
    unique_ptr<Channel> wakeup_channel_; 

    //所有channel的集合
    ChannelList active_channels_; 

    //pending中要执行的回调集合
    atomic<bool> calling_pending_functors_; 
    vector<Functor> pending_functors_;     

    //保护pending_functors
    mutex functor_mutex_;
};