#include<unistd.h>
#include<errno.h>
#include<cstring>
#include"epollpoller.h"
#include"logger.h"
#include"channel.h"

const int kNew = 0;
const int kAdded = 1;
const int kDeleted = 2;

EpollPoller::EpollPoller(EventLoop* loop) : Poller(loop), 
    epollfd_(epoll_create1(EPOLL_CLOEXEC)), events_(KinitEventlistSize)
{
    if(epollfd_ < 0)
    {
        LOG_FATAL("epoll create1 error: %d\n", errno);
    }
}

EpollPoller::~EpollPoller()
{
    close(epollfd_);
}

TimeStamp EpollPoller::poll(int timeout, ChannelList* active_channels)
{
    //__FUNCTION__是当前运行函数的函数名
    LOG_DEBUG("func = %s => fd total count: %d\n", __FUNCTION__, channels_.size());

    int events_num = epoll_wait(epollfd_, &events_[0], static_cast<int>(events_.size()), timeout);
    //记录可能的错误和事件发生时间
    int save_errno = errno;
    TimeStamp now(TimeStamp::now());
    if(events_num > 0)
    {
        LOG_DEBUG("%d events happend\n", events_num);
        fillActiveChannels(events_num, active_channels);
        //扩容
        if(events_num == events_.size())
        {
            events_.resize(events_num * 2);
        }
    }
    else if(events_num == 0)
    {
        LOG_DEBUG("%s timeout\n", __FUNCTION__);
    }
    else
    {
        if(save_errno != errno)
        {
            errno = save_errno;
            LOG_ERROR("EpollPoller::poll() error\n");
        }
    }
    return now;
}

void EpollPoller::updateChannel(Channel* channel)
{
    const int index = channel->index();
    LOG_INFO("func = %s fd = %d events = %d index = %d\n", __FUNCTION__, channel->getFd(), channel->getEvents(), index);

    //如果是新的channel，添加到poller中
    if(index == kNew || index == kDeleted)
    {
        int sockfd = channel->getFd();
        if(index == kNew)
        {
            channels_[sockfd] = channel;
        }
        channel->setIndex(kAdded);
        update(EPOLL_CTL_ADD, channel);
    }
    else
    {
        int sockfd = channel->getFd();
        //没有要监听的事件，删除fd
        if(channel->isNnoeEvent())
        {
            update(EPOLL_CTL_DEL, channel);
            channel->setIndex(kDeleted);
        }
        //修改为监听channel指定的事件
        else
        {
            update(EPOLL_CTL_MOD, channel);
        }
    }
}

void EpollPoller::removeChannel(Channel* channel)
{
    int index = channel->index();
    LOG_INFO("func = %s fd = %d events = %d index = %d\n", __FUNCTION__, channel->getFd(), channel->getEvents(), index);

    int sockfd = channel->getFd();
    channels_.erase(sockfd);
    if(index == kAdded)
    {
        update(EPOLL_CTL_DEL, channel);
    }
    channel->setIndex(kDeleted);
}

void EpollPoller::fillActiveChannels(int event_num, ChannelList* active_channels) const
{
    //记录活跃的channel
    for(int i = 0; i < event_num; ++i)
    {
        Channel *channel = static_cast<Channel*>(events_[i].data.ptr);
        channel->setRevent(events_[i].events);
        active_channels->push_back(channel);
    }
}

void EpollPoller::update(int operation, Channel* channel)
{
    int sockfd = channel->getFd();

    epoll_event event = {0};
    event.events = channel->getEvents();
    event.data.fd = sockfd;
    event.data.ptr = channel;

    if(epoll_ctl(epollfd_, operation, sockfd, &event) < 0)
    {
        if(operation == EPOLL_CTL_DEL)
        {
            LOG_ERROR("epoll_ctl del error: %d\n", errno);
        }
        else if(operation == EPOLL_CTL_ADD)
        {
            LOG_FATAL("epoll_ctl add error: %d\n", errno);
        }
        else
        {
            LOG_FATAL("epoll_ctl mod error: %d\n", errno);
        }
    }
}