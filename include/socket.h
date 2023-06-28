#pragma once

#include"noncopyable.h"

class InetAddress;

//封装socket
class Socket : public NonCopyable
{
public:
    explicit Socket(int sockfd) : sockfd_(sockfd) {}
    ~Socket();

    int getFd() {return sockfd_;}

    void bindAddress(const InetAddress& local_adress);
    void listen();
    int accept(InetAddress* peer_adress);

    //半关闭
    void shutdownWrite();

    //socket设置
    void setTcpNoDelay(bool on);
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void setKeepalive(bool on);

private:
    const int sockfd_;
};