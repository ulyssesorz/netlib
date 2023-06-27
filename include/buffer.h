#pragma once

#include<vector>
#include<string>
#include<algorithm>
#include"noncopyable.h"

using namespace std;

class Buffer : public NonCopyable
{
public:
    static const size_t kCheapPrepend = 8;
    static const size_t kInitialSize = 1024;
public:
    explicit Buffer(size_t init_size = kInitialSize) 
        : read_index_(kCheapPrepend), 
        write_index_(kCheapPrepend), 
        buffer_(kCheapPrepend + init_size) {}

    size_t readableBytes() const
    {
        return write_index_ - read_index_;
    }

    size_t writableBytes() const
    {
        return buffer_.size() - write_index_;
    }

    size_t prependableBytes() const
    {
        return read_index_;
    }

    //可读数据的起始地址
    const char* peek() const
    {
        return begin() + read_index_;
    }

    //读取数据产生偏移
    void retrieve(size_t len)
    {
        if(len < readableBytes())
        {
            read_index_ += len;
        }
        else
        {
            retrieveAll();
        }
    }

    void retrieveAll()
    {
        read_index_ = write_index_ = kCheapPrepend;
    }

    string retrieveAllAsString()
    {
        return retrieveAsString(readableBytes());
    }

    //读取指定长度的读区域
    string retrieveAsString(size_t len)
    {
        string result = string(peek(), len);
        retrieve(len);
        return result;
    }

    void ensureWritaleBytes(size_t len)
    {
        if(writableBytes() < len)
        {
            makeSpace(len);
        }
    }

    //写区域的起始地址
    char* beginWrite()
    {
        return begin() + write_index_;
    }

    void append(const char* data, size_t len)
    {
        ensureWritaleBytes(len);
        copy(data, data + len, beginWrite());
        write_index_ += len;
    }

    ssize_t readFd(int fd, int* save_errno);
    ssize_t writeFd(int fd, int* save_errno);

private:
    char* begin()
    {
        return &*buffer_.begin();
    }
    const char* begin() const
    {
        return &*buffer_.begin();
    }

    void makeSpace(size_t len)
    {
        if(prependableBytes() + writableBytes() < len + kCheapPrepend)
        {
            buffer_.resize(write_index_ + len);
        }
        else
        {
            size_t readable = readableBytes();
            copy(begin() + read_index_, begin() + write_index_, begin() + kCheapPrepend);
            read_index_ = kCheapPrepend;
            write_index_ = read_index_ + readable;
        }
    }

private:
    size_t read_index_;
    size_t write_index_;
    vector<char> buffer_;
};