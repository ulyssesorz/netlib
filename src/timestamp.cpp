#include<time.h>
#include"timestamp.h"

#define BUFFER_SIZE 128

TimeStamp TimeStamp::now()
{
    return TimeStamp(time(nullptr));
}

string TimeStamp::to_string()
{
    char buffer[BUFFER_SIZE];
    tm* times = localtime(&times_);
    //year-mon-day hour:min:sec
    snprintf(buffer, BUFFER_SIZE, "%4d-%02d-%02d %02d:%02d:%02d",
                times->tm_year + 1900,
                times->tm_mon + 1,
                times->tm_mday,
                times->tm_hour,
                times->tm_min,
                times->tm_sec);
    return buffer;
}