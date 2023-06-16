#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "./segment/segment.h"

#define NUM_FORKS 4

int main()
{
    // pid of the original process
    pid_t og = getpid();

    // segment usage of the original process
    SegmentInfo_show(PIDTYPE_PID);
    // flush before fork
    fflush(stdout);

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
            SegmentInfo_show(PIDTYPE_PID);
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