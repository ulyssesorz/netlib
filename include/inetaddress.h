#pragma once

#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>

using namespace std;

class InetAddress
{
public:
    explicit InetAddress(uint16_t port = 0, string ip = "127.0.0.1");
    explicit InetAddress(const sockaddr_in& addr) : addr_(addr) {}

    const sockaddr_in* getSockAddr() const {return &addr_;}
    void setSockAddr(const sockaddr_in& addr) {addr_ = addr;}

    string getIp() const;
    uint16_t getPort() const;
    string getIpAndPort() const;
private:
    sockaddr_in addr_;
};