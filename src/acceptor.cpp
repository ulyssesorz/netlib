#include<sys/types.h>
#include<sys/socket.h>
#include"acceptor.h"
#include"eventloop.h"
#include"inetaddress.h"
#include"logger.h"

static int createNonblockSockfd()
{
    //SOCK_CLOEXEC使监听套接字不被子进程继承
    int sockfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    if(sockfd < 0)
    {
        LOG_FATAL("%s : %s : %d listen socket create error: %d\n", __FILE__, __FUNCTION__, __LINE__, errno);
    }
    return sockfd;
}

Acceptor::Acceptor(EventLoop* loop, const InetAddress& listenaddr, bool reuseport) : 
    loop_(loop), accept_socket_(createNonblockSockfd()), 
    accept_channel_(loop, accept_socket_.getFd()), listenning_(false)
{
    //设置socket信息
    accept_socket_.setReuseAddr(true);
    accept_socket_.setReusePort(reuseport);
    accept_socket_.bindAddress(listenaddr);

    //channel绑定acceptor的handleread回调方法，用于建立连接
    accept_channel_.setReadCallback(bind(&Acceptor::handleRead, this));
}

Acceptor::~Acceptor()
{
    accept_channel_.disenableAll();
    accept_channel_.remove();
}

void Acceptor::listen()
{
    //socket开始监听连接请求，channel允许读（也即建立连接）
    listenning_ = true;
    accept_socket_.listen();
    accept_channel_.enableReading();
}

void Acceptor::handleRead()
{
    InetAddress addr;
    //accept建立连接
    int connfd = accept_socket_.accept(&addr);
    if(connfd > 0)
    {
        //执行回调（server中绑定的，功能是建立连接并分发给一个子loop）
        if(new_connection_callback_)
        {
            new_connection_callback_(connfd, addr);
        }
        else
        {
            close(connfd);
        }
    }
    else
    {
        LOG_ERROR("%s : %s : %d accept error: %d\n", __FILE__, __FUNCTION__, __LINE__, errno);
        if(errno == EMFILE)
        {
            LOG_ERROR("%s : %s : %d socket reached limit error: %d\n", __FILE__, __FUNCTION__, __LINE__, errno);
        }
    }
}
