#include<mutex>
#include<semaphore.h>
#include"thread.h"
#include"currentthread.h"

#define BUFFER_SIZE 64

atomic<int> Thread::thread_num_(0);

Thread::Thread(ThreadFunc func, const string& name) : started_(false), joined_(false),
    tid_(0), function_(move(func)), name_(name)
{
    setDefaultName();
}

Thread::~Thread()
{
    if(started_ && !joined_)
    {
        thread_->detach();
    }
}

void Thread::start()
{
    started_ = true;
    sem_t sem;
    sem_init(&sem, false, 0);
    thread_ = shared_ptr<thread>(new thread([&]()
    {
        tid_ = Current_thread::tid();
        sem_post(&sem);
        function_();
    }));
    sem_wait(&sem);
}

void Thread::join()
{
    joined_ = true;
    thread_->join();
}

//用线程id命名
void Thread::setDefaultName()
{
    int num = ++thread_num_;
    if(name_.empty())
    {
        char buffer[BUFFER_SIZE] = {0};
        snprintf(buffer, sizeof(buffer), "Thread %d", num);
    }
}