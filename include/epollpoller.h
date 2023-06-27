#include<sys/epoll.h>
#include<vector>
#include"poller.h"

using EventList = vector<epoll_event>;

class EpollPoller : public Poller
{
public:
    EpollPoller(EventLoop* loop);
    ~EpollPoller() override;

    TimeStamp poll(int timeout, ChannelList* active_channels) override;

    void updateChannel(Channel* channel) override;
    void removeChannel(Channel* channel) override;

private:
    //把活跃的channel记录到channellist里面
    void fillActiveChannels(int events_num, ChannelList* active_channels) const;
    //封装epoll_ctl
    void update(int operation, Channel* channel);

private:
    static const int KinitEventlistSize = 16;

private:
    int epollfd_;
    EventList events_;
};