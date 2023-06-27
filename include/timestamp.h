#pragma once

#include<string>
using namespace std;

class TimeStamp
{
public:
    explicit TimeStamp(int64_t times = 0);
    //返回当前时间
    static TimeStamp now();
    //把时间转化为字符串表示
    string to_string();
private:
    int64_t times_;
};