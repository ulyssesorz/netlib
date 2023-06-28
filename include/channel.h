#pragma once

#include<functional>
#include<memory>
#include"noncopyable.h"
#include"timestamp.h"

using namespace std;

using EventCallback = function<void()>;
using ReadEventCallback = function<void(TimeStamp)>;

class EventLoop;

//封装fd和回调方法
class Channel : NonCopyable
{
public:
    Channel(EventLoop* loop, int fd) : loop_(loop), fd_(fd), events_(0), real_events_(0),index_(0), tied_(false) {}
    ~Channel() {};

    //fd被触发时执行回调函数
    void handleEvent(TimeStamp receive_time);
    //tcp连接绑定channel
    void tie(const shared_ptr<void>& obj);
    //让所属loop移除自己
    void remove();

    //对外接口
    int getFd() const {return fd_;}
    int getEvents() const {return events_;}
    void setRevent(int revent) {real_events_ = revent;}
    bool isNnoeEvent() const {return events_ == kNoneEvent;}
    EventLoop* ownerLoop() {return loop_;}
    int index() {return index_;}
    void setIndex(int index) {index_ = index;}

public:
    //修改要监听的事件
    void enableReading()
    {
        events_ |= kReadEvent;
        update();
    }
    void disenableReading()
    {
        events_ &= ~kReadEvent;
        update();
    }
    void enableWriting()
    {
        events_ |= kWriteEvent;
        update();
    }
    void disenabelWriting()
    {
        events_ &= ~kWriteEvent;
        update();
    }
    void disenableAll()
    {
        events_ = kNoneEvent;
        update();
    }

    bool isNoneEvent() const {return events_ == kNoneEvent;}
    bool isWriting() const {return events_ & kWriteEvent;}
    bool isReading() const {return events_ & kReadEvent;}

    //绑定回调
    void setReadCallback(ReadEventCallback callback) {read_callback_ = move(callback);}
    void setWriteCompleteCallback(EventCallback callback) {write_callback_ = move(callback);}
    void setCloseCallback(EventCallback callback) {close_callback_ = move(callback);}
    void setErrorCallback(EventCallback callback) {error_callback_ = move(callback);}

private:
    //向poller更新监听的事件
    void update();
    //根据事件执行相应的回调
    void handleEventWithGuard(TimeStamp receive_time);

    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;

private:
    //所属loop
    EventLoop* loop_;
    //封装的fd
    const int fd_;
    //要监听的事件
    int events_;

    //poller发生的事件
    int real_events_;
    //channel在poller里的状态（0: new, 1: add, 2: delete)
    int index_;

    //channel观察tcp连接的状态
    weak_ptr<void> tie_;
    bool tied_;

    //fd的回调方法
    ReadEventCallback read_callback_;
    EventCallback write_callback_;
    EventCallback close_callback_;
    EventCallback error_callback_;
};