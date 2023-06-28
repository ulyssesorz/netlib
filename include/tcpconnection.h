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

//继承后对象可以通过shared_from_this方法获得一个指向自身的shared_ptr
class TcpConnection : NonCopyable, public enable_shared_from_this<TcpConnection>
{
private:
    //连接的状态
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

    //对外接口
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
    //给channel绑定的回调方法
    void handleRead(TimeStamp receive_time);
    void handleWrite();
    void handleClose();
    void handleError();

    //在连接包含的loop中进行读写
    void sendInLoop(const string& buf);
    //在连接包含的loop中关闭连接
    void shutdownInLoop();

private:
    //连接所属的loop
    EventLoop* loop_; 
    const string name_;

    atomic<int> state_;
    bool reading_;

    //所属的socket和channel
    unique_ptr<Socket> socket_;
    unique_ptr<Channel> channel_;

    //本端地址和对端地址
    const InetAddress local_addr_;
    const InetAddress peer_addr_;

    //新连接
    ConnectionCallback connection_callback_;        
    //读写消息
    MessageCallback message_callback_;              
    //发送完信息
    WriteCompleteCallback write_complete_callback_; 
    //关闭连接
    CloseCallback close_callback_;
    //高水位
    HighWaterMarkCallback high_water_mark_callback_;
    size_t high_water_mark_; 

    //收发数据的缓冲区
    Buffer input_buffer_;  
    Buffer output_buffer_;
};