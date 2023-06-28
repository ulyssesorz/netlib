#pragma once
#include<memory>
#include<string>
#include<atomic>
#include<functional>
#include<unordered_map>
#include"eventloop.h"
#include"eventloopthreadpool.h"
#include"tcpconnection.h"
#include"acceptor.h"
#include"inetaddress.h"
#include"noncopyable.h"
#include"callbacks.h"
#include"buffer.h"
#include"logger.h"

using namespace std;

using ThreadInitCallback = function<void(EventLoop*)>;
using ConnectionMap = unordered_map<string, TcpConnectionPtr>;

class TcpServer : NonCopyable
{
public:
    enum Option
    {
        kNoReusePort,
        kReusePort,  
    };

public:
    TcpServer(EventLoop *loop, const InetAddress &listenaddr, const string& name, Option option = kNoReusePort);
    ~TcpServer();

    //设置回调
    void setThreadInitCallback(const ThreadInitCallback &callback) { thread_init_callback_ = callback; }
    void setConnectionCallback(const ConnectionCallback &callback) { connection_callback_ = callback; }
    void setMessageCallback(const MessageCallback &callback) { message_callback_ = callback; }
    void setWriteCompleteCallback(const WriteCompleteCallback &callback) { write_complete_callback_ = callback; }

    void setThreadNum(int thread_num);

    void start();

private:
    void newConnection(int sockfd, const InetAddress& peer_addr);
    void removeConnection(const TcpConnectionPtr& conn);
    void removeConnectionInLoop(const TcpConnectionPtr& conn);

private:
    //主loop
    EventLoop* loop_;
    const string ip_port_;
    const string name_;

    unique_ptr<Acceptor> acceptor_;               
    shared_ptr<EventLoopThreadPool> thread_pool_; 

    //回调
    ConnectionCallback connection_callback_;       
    MessageCallback message_callback_;              
    WriteCompleteCallback write_complete_callback_; 

    ThreadInitCallback thread_init_callback_; 

    atomic<int> started_;
    int next_conn_id_;

    //name : conn的映射
    ConnectionMap connections_; 
};