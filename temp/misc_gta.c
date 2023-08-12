#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <asm/ldt.h>
#include <errno.h>
#include <sys/syscall.h>
#include <unistd.h>

#include "./segment/segment.h"
#include "./wsl/wsl.h"

typedef struct user_desc user_desc_t;
int get_thread_area(user_desc_t* p_desc);

int main()
{
    SegmentInfo_show(PIDTYPE_PID);

    struct user_desc desc;
    printf("XX: base: %u, limit: %u\n", desc.base_addr, desc.limit);
    int rc = 11;

    desc.entry_number = 0;
    rc = get_thread_area(&desc);
    printf("CS: base: %u, limit: %u\n", desc.base_addr, desc.limit);

    desc.entry_number = 43;
    rc = get_thread_area(&desc);
    printf("SS: base: %u, limit: %u\n", desc.base_addr, desc.limit);

    if( is_wsl() )
    {
        printf("YOU ARE INSIDE WSL\n");
    }
    else
    {
        printf("YOU ARE NOT INSIDE WSL\n");
    }

    return 0;
}

int get_thread_area(user_desc_t* p_desc)
{
    #ifndef __i386__
        #ifndef __x86_64__
            printf("Neither of the headers is defined...\n");
        #else
            printf("Only __x86_64__ is defined...\n");
        #endif
    #else
        #ifndef __x86_64__
            printf("Only __i386__ is defined...\n");
        #else
            printf("Both __i386__ and __x86_64__ are defined\n");
        #endif
    #endif

    #ifdef SYS_get_thread_area
        printf("Making syscall %d\n", SYS_get_thread_area);
        int rc = syscall(SYS_get_thread_area, p_desc);
        if( 0 != rc )
        {
            printf("Error: get_thread_area(): non-zero return code = %d, errno = %d\n", rc, errno);
            return rc;
        }
    #else
        #error "CompileError: SYS_get_thread_area not defined"
    #endif
}