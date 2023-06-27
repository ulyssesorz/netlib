#include<sys/epoll.h>
#include"channel.h"
#include"eventloop.h"
#include"logger.h"

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent = EPOLLOUT;

void Channel::handleEvent(TimeStamp receive_time)
{
    //如果已经绑定了tcp连接，尝试提升为强引用，若成功说明连接还保持着，可以执行回调
    //若没有绑定连接则不用关心这一点
    if(tied_)
    {
        shared_ptr<void> guard = tie_.lock();
        if(guard)
        {
            handleEventWithGuard(receive_time);
        }
    }
    else
    {
        handleEventWithGuard(receive_time);
    }
}

void Channel::tie(const shared_ptr<void>& obj)
{
    //获取tcp connection传来的shared指针，用于检测连接是否断开
    tied_ = true;
    tie_ = obj;    
}

void Channel::remove()
{
    loop_->removeChannel(this);
}

void Channel::update()
{
    loop_->updateChannel(this);
}

void Channel::handleEventWithGuard(TimeStamp receive_time)
{
    LOG_INFO("channel handle revent: %d\n", real_events_);

    if((real_events_ & EPOLLHUP) && !(real_events_ & EPOLLIN))
    {
        if(close_callback_)
        {
            close_callback_();
        }
    }    
    if(real_events_ & EPOLLERR)
    {
        if(error_callback_)
        {
            error_callback_();
        }
    }
    if(real_events_ & (EPOLLIN | EPOLLPRI))
    {
        if(read_callback_)
        {
            read_callback_(receive_time);
        }
    }
    if(real_events_ & EPOLLOUT)
    {
        if(write_callback_)
        {
            write_callback_();
        }
    }
}


