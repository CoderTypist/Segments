#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include "threads.h"


pid_t gettid()
{
    #ifdef SYS_gettid
        pid_t tid = syscall(SYS_gettid);
        return tid;
    #else
        #error "CompileError: threads.c: gettid(): SYS_gettid is not defined. Unable to make a syscall to get thread id."
    #endif
}