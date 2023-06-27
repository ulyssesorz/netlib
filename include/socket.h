#pragma once

#include"noncopyable.h"

class InetAddress;

class Socket : public NonCopyable
{
public:
    explicit Socket(int sockfd) : sockfd_(sockfd) {}
    ~Socket();

    int getFd() {return sockfd_;}

    void bindAddress(const InetAddress& local_adress);
    void listen();
    int accept(InetAddress* peer_adress);

    void shutdownWrite();

    void setTcpNoDelay(bool on);
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void setKeepalive(bool on);

private:
    const int sockfd_;
};