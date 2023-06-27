#pragma once

#include<string>
#include"noncopyable.h"

using namespace std;

#define BUFFER_SIZE 1024

//日志级别
enum EnLogLevel
{
    INFO,   //普通信息
    ERROR,  //错误信息
    FATAL,  //core信息
    DEBUG,  //调试信息
};

class Logger : NonCopyable
{
public:
    //单例模式，获取日志实例
    static Logger& instance();
    //设置日志级别
    void setLogLevel(EnLogLevel level);
    //写日志
    void log(string msg);

    void setOpen(bool flag) {open_ = flag;}
    bool isOpen() {return open_;}

private:
    Logger() : open_(true) {};
    ~Logger() = default;
private:
    int log_level_;
    bool open_;
};

#define LOG_INFO(logmsgFormat, ...)                       \
    do                                                    \
    {                                                     \
        Logger& logger = Logger::instance();              \
        if(logger.isOpen())                                    \
        {                                                 \
            logger.setLogLevel(EnLogLevel::INFO);           \
            char buf[BUFFER_SIZE] = {0};                      \
            snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
        }                                                   \
    } while (0)

#define LOG_ERROR(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger& logger = Logger::instance();              \
        if(logger.isOpen())                                            \
        {                                                   \
            logger.setLogLevel(EnLogLevel::ERROR);          \
            char buf[BUFFER_SIZE] = {0};                      \
            snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
        }                                                   \
    } while (0)

#define LOG_FATAL(logmsgFormat, ...)                      \
    do                                                    \
    {                                                       \
        Logger& logger = Logger::instance();                \
        if(logger.isOpen())                                     \
        {                                                    \
            logger.setLogLevel(EnLogLevel::FATAL);          \
            char buf[BUFFER_SIZE] = {0};                      \
            snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
            exit(-1);                                         \
        }                                                   \
    } while (0)

#if MUDEBUG
#define LOG_DEBUG(LogmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::instance();              \
        if(logger.isOpen())                                            \
        {                                                    \
            logger.setLogLevel(EnLogLevel::DEBUG);          \
            char buf[BUFFER_SIZE] = {0};                      \
            snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf);                                  \
        }                                                      \
    } while (0)
#else
#define LOG_DEBUG(logmsgFormat, ...)
#endif