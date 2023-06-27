#include<iostream>
#include"logger.h"
#include"timestamp.h"

Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}

void Logger::setLogLevel(EnLogLevel level)
{
    log_level_ = level;
}

void Logger::log(string msg)
{
    switch(log_level_)
    {
        case INFO:
            cout << "[INFO]";
            break;
        case ERROR:
            cout << "[ERROR]";
            break;
        case FATAL:
            cout << "[FATAL]";
            break;
        case DEBUG:
            cout << "[DEBUG]";
            break;
        default:
            break;
    }
    cout << TimeStamp::now().to_string() << " : " << msg << endl; 
}