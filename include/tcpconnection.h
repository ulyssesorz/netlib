#pragma once
#include<string>
#include<atomic>
#include<memory>
#include"noncopyable.h"
#include"inetaddress.h"
#include"timestamp.h"
#include"callbacks.h"
#include "buffer.h"

using namespace std;

class Channel;
class EventLoop;
class Socket;

class TcpConnection : NonCopyable, public enable_shared_from_this<TcpConnection>
{
private:
    enum State
    {
        kDisconnected,
        kConnecting, 
        kConnected, 
        kDisconnecting,
    };

public:
    TcpConnection(EventLoop* loop, const string name, int sockfd, const InetAddress& local_addr, const InetAddress& peer_addr);
    ~TcpConnection();

    EventLoop* getLoop() const { return loop_; }

    const string& getName() const { return name_; }

    const InetAddress& getLocaladdr() const { return local_addr_; }

    const InetAddress& getPeeraddr() const { return peer_addr_; }

    bool connected() { return state_ == kConnected; }

    void setState(State state) { state_ = state; }

    //发送数据
    void send(const string& buf);

    //断开连接
    void shutdown();

    //建立连接
    void establishConnection();

    //销毁连接
    void destroyConnection();

    //设置回调
    void setCloseCallback(const CloseCallback &callback) { close_callback_ = callback; }
    void setHighwaterCallback(const HighWaterMarkCallback &callback) { high_water_mark_callback_ = callback; }
    void setConnectionCallback(const ConnectionCallback &callback) { connection_callback_ = callback; }
    void setMessageCallback(const MessageCallback &callback) { message_callback_ = callback; }
    void setWriteCompleteCallback(const WriteCompleteCallback &callback) { write_complete_callback_ = callback; }

private:
    void handleRead(TimeStamp receive_time);
    void handleWrite();
    void handleClose();
    void handleError();

    void sendInLoop(const string& buf);
    void shutdownInLoop();

private:
    EventLoop* loop_; 
    const string name_;

    atomic<int> state_;
    bool reading_;

    unique_ptr<Socket> socket_;
    unique_ptr<Channel> channel_;

    const InetAddress local_addr_;
    const InetAddress peer_addr_;

    ConnectionCallback connection_callback_;        //有新连接时回调
    MessageCallback message_callback_;              //有读写消息的回调
    WriteCompleteCallback write_complete_callback_; //消息发送完以后的回调
    CloseCallback close_callback_;
    HighWaterMarkCallback high_water_mark_callback_;
    size_t high_water_mark_; //高水位标志

    Buffer input_buffer_;  //接收数据的缓冲区
    Buffer output_buffer_; //发送数据的缓冲区
};