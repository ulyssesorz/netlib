#include"poller.h"

bool Poller::hasChannel(Channel* channel) const
{
    auto it = channels_.find(channel->getFd());
    return it != channels_.end() && it->second == channel;
}