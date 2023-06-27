#include"currentthread.h"

namespace Current_thread
{
    __thread int t_cachedTid = 0;

    void cache_tid()
    {
        //获取tid值
        if(t_cachedTid == 0)
        {
            t_cachedTid = static_cast<pid_t>(syscall(SYS_getpid));
        }
    }
}