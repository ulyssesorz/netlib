#include<netlib/tcpserver.h>
#include<string>
#include<functional>

using namespace std;
using namespace placeholders;

class EchoServer
{
public:
    EchoServer(EventLoop* loop, InetAddress& addr, string name) : server_(loop, addr, name), loop_(loop)
    {
        server_.setConnectionCallback(bind(&EchoServer::onConnection, this, _1));
        server_.setMessageCallback(bind(&EchoServer::onMessage, this, _1, _2, _3));
        server_.setThreadNum(3);
    }

    void start()
    {
        server_.start();
    }

private:
    void onConnection(const TcpConnectionPtr& conn)
    {
        if(conn->connected())
        {
            LOG_INFO("connection up: %s", conn->getPeeraddr().getIpAndPort().c_str());
        }
        else
        {
            LOG_INFO("connection down: %s", conn->getPeeraddr().getIpAndPort().c_str());
        }
    }
    void onMessage(const TcpConnectionPtr& conn, Buffer* buffer, TimeStamp time)
    {
        string msg = buffer->retrieveAllAsString();
        conn->send(msg);
        conn->shutdown();
    }
private:
    EventLoop* loop_;
    TcpServer server_;
};

int main()
{
    Logger& logger = Logger::instance();
    logger.setOpen(true);
    EventLoop loop;
    InetAddress addr(8081);
    EchoServer server(&loop, addr, "echo server");
    server.start();
    loop.loop();
    
    return 0;
}