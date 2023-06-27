#include<cstdlib>
#include"poller.h"
#include"epollpoller.h"

Poller*  Poller::newDefaultPoller(EventLoop* loop)
{
    if(getenv("MUDUO_USE_POLL"))
    {
        return nullptr;
    }
    else
    {
        return new EpollPoller(loop);
    }
}