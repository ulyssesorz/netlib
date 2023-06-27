#include<cstring>
#include"inetaddress.h"

#define BUFFER_SIZE 64

InetAddress::InetAddress(uint16_t port, string ip)
{
    addr_ = {0};
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}

string InetAddress::getIp() const
{
    char buffer[BUFFER_SIZE] = {0};
    inet_ntop(AF_INET, &addr_.sin_addr, buffer, BUFFER_SIZE);
    return buffer;
}

uint16_t InetAddress::getPort() const
{
    return ntohs(addr_.sin_port);
}

string InetAddress::getIpAndPort() const
{
    uint16_t port = getPort();
    char buffer[BUFFER_SIZE] = {0};
    sprintf(buffer, " : %u", port);
    return getIp() + buffer;
}
