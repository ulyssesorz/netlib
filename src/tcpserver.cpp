#include<strings.h>
#include"tcpserver.h"

using namespace placeholders;

#define BUFFER_SIZE64 64

EventLoop* checkLoopNotNull(EventLoop* loop)
{
    if(loop == nullptr)
    {
        LOG_FATAL("%s : %s : %d main loop is null\n", __FILE__, __FUNCTION__, __LINE__);
    }
    return loop;
}

TcpServer::TcpServer(EventLoop* loop, const InetAddress& listenaddr, const string& name, Option option) : 
    loop_(checkLoopNotNull(loop)), ip_port_(listenaddr.getIpAndPort()), name_(name),
    acceptor_(new Acceptor(loop, listenaddr, option == kReusePort)), thread_pool_(new EventLoopThreadPool(loop, name)), 
    connection_callback_(), message_callback_(), next_conn_id_(1), started_(0)
{
    acceptor_->setNewConnectionCallback(bind(&TcpServer::newConnection, this, _1, _2));
}

TcpServer::~TcpServer()
{
    //关闭所有连接
    for(auto& it : connections_)
    {
        TcpConnectionPtr ptr(it.second);
        //引用计数置1，退出循环后释放资源
        it.second.reset();
        ptr->getLoop()->runInLoop(bind(&TcpConnection::destroyConnection, ptr));
    }
}

void TcpServer::setThreadNum(int thread_num)
{
    thread_pool_->setThreadNum(thread_num);
}

void TcpServer::start()
{
    //检查started值防止重复开启
    if(started_++ == 0)
    {
        //开启线程池和监听loop
        thread_pool_->start(thread_init_callback_);
        loop_->runInLoop(bind(&Acceptor::listen, acceptor_.get()));
    }
}

void TcpServer::newConnection(int sockfd, const InetAddress& peer_addr)
{
    //选择一个loop接收新连接
    EventLoop* ioloop = thread_pool_->getNextEventLoop();

    //创建连接名（loop+ip+端口+序号）
    char buf[BUFFER_SIZE64] = {0};
    snprintf(buf, sizeof(buf), "-%s#%d", ip_port_.c_str(), next_conn_id_);
    ++next_conn_id_;
    string conn_name = name_ + buf;

    LOG_INFO("tcp server::new connection[%s] -new connecion[%s] from %s\n", name_.c_str(), conn_name.c_str(), peer_addr.getIpAndPort().c_str());

    //创建socket地址
    sockaddr_in addr = {0};
    socklen_t addrlen = sizeof(addr);
    if(::getsockname(sockfd, (sockaddr*)&addr, &addrlen) < 0)
    {
        LOG_ERROR("new connection get localaddr error\n");
    }
    InetAddress local_addr(addr);

    //创建tcp连接
    TcpConnectionPtr conn(new TcpConnection(ioloop, conn_name, sockfd, local_addr, peer_addr));
    connections_[conn_name] = conn;

    //绑定回调方法
    conn->setConnectionCallback(connection_callback_);
    conn->setMessageCallback(message_callback_);
    conn->setWriteCompleteCallback(write_complete_callback_);
    conn->setCloseCallback(bind(&TcpServer::removeConnection, this, _1));
    //在loop中建立连接
    ioloop->runInLoop(bind(&TcpConnection::establishConnection, conn));
}

void TcpServer::removeConnection(const TcpConnectionPtr& conn)
{
    //由主loop来关闭子loop的连接
    loop_->runInLoop(bind(&TcpServer::removeConnectionInLoop, this, conn));
}

void TcpServer::removeConnectionInLoop(const TcpConnectionPtr& conn)
{
    LOG_INFO("tcp server::remove connection in loop[%s]-connecion[%s]\n", name_.c_str(), conn->getName().c_str());

    connections_.erase(conn->getName());
    EventLoop* ioloop = conn->getLoop();
    //连接对应的loop来关闭连接
    ioloop->queueInLoop(bind(&TcpConnection::destroyConnection, conn));
}