#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/tcp.h>
#include<unistd.h>
#include"socket.h"
#include"logger.h"
#include"inetaddress.h"

Socket::~Socket()
{
    close(sockfd_);
}

void Socket::bindAddress(const InetAddress& local_address)
{
    if(bind(sockfd_, (sockaddr*)local_address.getSockAddr(), sizeof(sockaddr_in)) != 0)
    {
        LOG_FATAL("bind sockfd: %d fail\n", sockfd_);
    }
} 

void Socket::listen()
{
    if(::listen(sockfd_, 1024) != 0)
    {
        LOG_FATAL("listen sockfd: %d fail\n", sockfd_);
    }
}

int Socket::accept(InetAddress* peer_address)
{
    sockaddr_in addr = {0};
    socklen_t len = sizeof(addr);

    int connfd = ::accept4(sockfd_, (sockaddr*)&addr, &len, SOCK_NONBLOCK | SOCK_CLOEXEC);
    if(connfd >= 0)
    {
        peer_address->setSockAddr(addr);
    }
    return connfd;
}

void Socket::shutdownWrite()
{
    if(::shutdown(sockfd_, SHUT_WR) < 0)
    {
        LOG_ERROR("shutdown write error");
    }
}

//禁用nagel算法，立即发送包
void Socket::setTcpNoDelay(bool on)
{
    int optval = on ? 1 : 0;
    setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));
}

//地址复用，可以绑定处于time_wait的ip和port
void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;
    setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
}

//端口复用，多个socket绑定到同一个ip和port
void Socket::setReusePort(bool on)
{
    int optval = on ? 1 : 0;
    setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));
}

//开启socket保活机制
void Socket::setKeepalive(bool on)
{
    int optval = on ? 1 : 0;
    setsockopt(sockfd_, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval));
}