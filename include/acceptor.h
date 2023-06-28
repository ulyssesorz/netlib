#pragma once
#include<functional>
#include"noncopyable.h"
#include"socket.h"
#include"channel.h"

using namespace std;

class EventLoop;
class InetAddress;

//接受新连接的回调函数
using NewConnectionCallback = function<void(int, const InetAddress&)>;

//负责建立tcp连接，包含主loop
class Acceptor : NonCopyable
{
public:
    Acceptor(EventLoop *loop, const InetAddress &listenaddr, bool reuseport);
    ~Acceptor();

    void setNewConnectionCallback(const NewConnectionCallback& callback) {new_connection_callback_ = callback;}
    bool isListening() {return listenning_;}

    void listen();

private:
    //用于接受新连接的请求
    void handleRead();

private:
    //主loop
    EventLoop *loop_; 

    bool listenning_;

    //监听套接字和channel
    Socket accept_socket_;
    Channel accept_channel_;

    NewConnectionCallback new_connection_callback_;
};