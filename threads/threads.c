
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "threads.h"


pid_t gettid()
{
    #ifdef SYS_gettid
        pid_t tid = syscall(SYS_gettid);
        return tid;
    #else
        fprintf(stderr, "Error: %s: %s: SYS_gettid is not defined. Unable to make a syscall to get thread id.\n", __FILE__, __func__);
        exit(-1);
    #endif
}