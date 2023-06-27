#pragma once
#include<vector>
#include<unordered_map>
#include"noncopyable.h"
#include"channel.h"

class EventLoop;

using ChannelList = vector<Channel*>;
using ChannelMap = unordered_map<int, Channel*>;

//多路分发器基类
class Poller : NonCopyable
{
public:
    Poller(EventLoop *loop) : owner_loop_(loop) {};
    virtual ~Poller() = default;

    //io复用统一接口
    virtual TimeStamp poll(int timeout, ChannelList* active_channels) = 0;
    //增删channel的接口
    virtual void updateChannel(Channel* channel) = 0;
    virtual void removeChannel(Channel* channel) = 0;

    bool hasChannel(Channel* channel) const;
    //创建poller
    static Poller* newDefaultPoller(EventLoop* loop);

protected:
    //fd : channel的映射
    ChannelMap channels_;

private:
    //poller所属的loop
    EventLoop* owner_loop_; 
};