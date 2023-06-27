#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<functional>
#include"tcpconnection.h"
#include"socket.h"
#include"channel.h"
#include"eventloop.h"
#include"logger.h"

using namespace placeholders;

static EventLoop* checkLoopNotNull(EventLoop* loop)
{
    if(loop == nullptr)
    {
        LOG_FATAL("%s : %s : %d tcpconnecion is null\n", __FILE__, __FUNCTION__, __LINE__);
    }
    return loop;
}

TcpConnection::TcpConnection(EventLoop* loop, const string name, int sockfd, const InetAddress& local_addr, const InetAddress& peer_addr) : 
    loop_(checkLoopNotNull(loop)), name_(name), state_(kConnecting), reading_(true), socket_(new Socket(sockfd)), 
    channel_(new Channel(loop, sockfd)), local_addr_(local_addr), peer_addr_(peer_addr), high_water_mark_(64 * 1024 * 1024)
{
    channel_->setReadCallback(bind(&TcpConnection::handleRead, this, _1));
    channel_->setWriteCompleteCallback(bind(&TcpConnection::handleWrite, this));
    channel_->setCloseCallback(bind(&TcpConnection::handleClose, this));
    channel_->setErrorCallback(bind(&TcpConnection::handleError, this));

    LOG_INFO("tcp connection::ctor[%s] at fd = %d\n", name_.c_str(), sockfd);
    socket_->setKeepalive(true);
}

TcpConnection::~TcpConnection()
{
    LOG_INFO("tcp connection::dtor[%s] at fd = %d state = %d\n", name_.c_str(), channel_->getFd(), static_cast<int>(state_));
}

void TcpConnection::send(const string& buf)
{
    if(state_ == kConnected)
    {
        //在当前loop的线程里，发送数据
        if(loop_->isInLoopthread())
        {
            sendInLoop(buf);
        }
        //否则绑定回调，稍后发送
        else
        {
            loop_->runInLoop(bind(&TcpConnection::sendInLoop, this, buf));
        }
    }
}

void TcpConnection::sendInLoop(const string& buf)
{
    if(state_ == kDisconnected)
    {
        LOG_ERROR("disconnected, give up writing\n");
    }    

    size_t remaining = buf.size();
    ssize_t nwrote = 0;
    bool fault_error = false;

    //channel开始写数据，且缓冲区为空
    if(!channel_->isWriting() && output_buffer_.readableBytes() == 0)
    {
        nwrote = write(channel_->getFd(), buf.c_str(), buf.size());
        if(nwrote >= 0)
        {
            //buf剩余未写入缓冲区的数据
            remaining = buf.size() - nwrote;
            //都写入了，让loop执行complete的回调
            if(remaining == 0 && write_complete_callback_)
            {
                //安全地传递this指针
                loop_->queueInLoop(bind(write_complete_callback_, shared_from_this()));
            }
        }
    }
    else
    {
        nwrote = 0;
        //非正常阻塞，说明出错
        if(errno != EWOULDBLOCK)
        {
            LOG_ERROR("tcp connection::send int loop\n");
            if(errno == EPIPE || errno == ECONNRESET)
            {
                fault_error = true;
            }
        }
    }
    if(!fault_error && remaining > 0)
    {
        //缓冲区待发送的数据长度
        size_t oldlen = output_buffer_.readableBytes();
        if(oldlen + remaining >= high_water_mark_ && oldlen < high_water_mark_)
        {
            loop_->queueInLoop(bind(high_water_mark_callback_, shared_from_this(), oldlen + remaining));
        }   
        //buf没有全部发送出去，剩余数据需放入缓冲区
        output_buffer_.append(buf.c_str() + nwrote, remaining);
        if(!channel_->isWriting())
        {
            channel_->enableWriting();
        }
    }
}

void TcpConnection::shutdown()
{
    //修改状态，让loop执行回调关闭写端
    if(state_ == kConnected)
    {
        setState(kDisconnecting);
        loop_->runInLoop(bind(&TcpConnection::shutdownInLoop, this));
    }
}

void TcpConnection::shutdownInLoop()
{
    if(!channel_->isWriting())
    {
        socket_->shutdownWrite();
    }
}

void TcpConnection::establishConnection()
{
    //设置状态，让channel绑定连接，并准备读
    setState(kConnected);
    channel_->tie(shared_from_this());
    channel_->enableReading();
    connection_callback_(shared_from_this());
}

void TcpConnection::destroyConnection()
{   
    //创建的逆操作
    if(state_ == kConnected)
    {
        setState(kDisconnected);
        channel_->disenableAll();
    }
    channel_->remove();
}

void TcpConnection::handleRead(TimeStamp receive_time)
{
    int save_errno = 0;
    ssize_t n = input_buffer_.readFd(channel_->getFd(), &save_errno);
    if(n > 0)
    {
        message_callback_(shared_from_this(), &input_buffer_, receive_time);
    }
    //连接关闭
    else if(n == 0)
    {
        handleClose();
    }
    else
    {
        errno = save_errno;
        LOG_ERROR("tcp connection::handle read\n");
        handleError();
    }
}

void TcpConnection::handleWrite()
{
    if(channel_->isWriting())
    {
        int save_errno = 0;
        ssize_t n = output_buffer_.writeFd(channel_->getFd(), &save_errno);
        if(n > 0)
        {
            //移动n位
            output_buffer_.retrieve(n);
            //没有待发送的数据，说明写操作完成
            if(output_buffer_.readableBytes() == 0)
            {
                channel_->disenabelWriting();
                if(write_complete_callback_)
                {
                    loop_->queueInLoop(bind(write_complete_callback_, shared_from_this()));
                }
                //写完就要关闭连接
                if(state_ == kDisconnecting)
                {
                    shutdownInLoop();
                }
            }
        }
        else
        {
            LOG_ERROR("tcp connection::handle write\n");
        }
    }
    else
    {
        LOG_ERROR("tcp connection fd = %d is down, no more send\n", channel_->getFd());
    }
}

void TcpConnection::handleClose()
{
    LOG_INFO("fd = %d state =  %d", channel_->getFd(), static_cast<int>(state_));

    setState(kDisconnected);
    channel_->disenableAll();

    TcpConnectionPtr ptr(shared_from_this());
    connection_callback_(ptr);
    close_callback_(ptr);
}

void TcpConnection::handleError()
{
    int optval;
    socklen_t optlen = sizeof(optval);
    int save_errno = 0;

    if(::getsockopt(channel_->getFd(), SOL_SOCKET, SO_ERROR, &optval, &optlen) < 0)
    {
        save_errno = errno;
    }
    else
    {
        save_errno = optval;
    }
    LOG_ERROR("tcp connection handle error name: %s SO_ERROR: %d", name_.c_str(), save_errno);
}