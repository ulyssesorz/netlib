#include<errno.h>
#include<unistd.h>
#include<sys/uio.h>
#include"buffer.h"

ssize_t Buffer::readFd(int fd, int* save_errno)
{
    char extra_buffer[65536] = {0};
    struct iovec vec[2];
    const size_t writable = writableBytes();
    
    vec[0].iov_base = begin() + write_index_;
    vec[0].iov_len = writable;
    vec[1].iov_base = extra_buffer;
    vec[1].iov_len = sizeof(extra_buffer);

    const int count = writable < sizeof(extra_buffer) ? 2 : 1;
    const ssize_t n = readv(fd, vec, count);

    if(n < 0)
    {
        *save_errno = errno;
    }
    else if(n <= writable)
    {
        write_index_ += n;
    }
    else
    {
        write_index_ = buffer_.size();
        append(extra_buffer, n - writable);
    }
    return n;
}

ssize_t Buffer::writeFd(int fd, int* save_errno)
{
    ssize_t n = write(fd, peek(), readableBytes());
    if(n < 0)
    {
        *save_errno = errno;
    }
    return n;
}