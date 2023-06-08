#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "./segment/selector.h"
#include "./segment/descriptor.h"

#define NUM_FORKS 4

void segment_info();

int main()
{
    // pid of the original process
    pid_t og = getpid();

    int i;
    for( i = 0 ; i < NUM_FORKS ; i++ )
    {
        pid_t ret = fork();

        // error forking
        if( -1 == ret )
        {
            fprintf(stderr, "Error: fork() failed: i = %d\n", i);
            exit(-1);
        }

        // child prints segment info
        if( 0 == ret )
        {
            printf("pid: %d, i: %d\n", getpid(), i);
            segment_info();
            break;
        }
    }

    // sleep to ensure all processes print segment info before exiting
    sleep(2);

    // all child processes exit
    if( getpid() != og )
        return 0;

    // parent waits for all children before exiting
    while( wait(NULL) > 0 );

    return 0;
}

void segment_info()
{
    pid_t pid = getpid();
    printf("pid_t: %-10d ---------------------------------------------------------\n", pid);

    printf("pid_t: %d", pid);
    SegmentSelector_print_CS();

    printf("pid_t: %d", pid);
    SegmentSelector_print_SS();

    printf("pid_t: %d", pid);
    SegmentSelector_print_DS();
    
    printf("pid_t: %d", pid);
    SegmentSelector_print_ES();

    printf("pid_t: %d", pid);
    SegmentSelector_print_FS();

    printf("pid_t: %d", pid);
    SegmentSelector_print_GS();

    printf("pid_t: %d", pid);
    SegmentSelector_print_TR();

    printf("pid_t: %d", pid);
    SegmentSelector_print_LDTR();
}