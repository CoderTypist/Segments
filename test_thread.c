#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "./segment/segment.h"

#define NUM_THREADS 5

pthread_mutex_t lock;

void* print_thread_segment_info(void*);


int main()
{
    int res = pthread_mutex_init(&lock, NULL);
    if( res != 0 )
    {
        fprintf(stderr, "Error: main(): Failed to initialize mutex lock: error code = %d\n", res);
        exit(-1);
    }
    
    SegmentInfo_thread();
    pthread_t tids[NUM_THREADS-1];
    int i;
    for( i = 0 ; i < NUM_THREADS-1 ; i++ )
    {
        int res = pthread_create(&tids[i], NULL, print_thread_segment_info, NULL);
        if( res != 0 )
        {
            fprintf(stderr, "Error: main(): Unable to create thread: error code = %d\n", res);
            exit(-1);
        }
    }
    for( i = 0 ; i < NUM_THREADS-1 ; i++ )
        pthread_join(tids[i], NULL);

    return 0;
}

void* print_thread_segment_info(void*)
{
    pthread_mutex_lock(&lock);
    SegmentInfo_thread();
    pthread_mutex_unlock(&lock);
    sleep(1);
    return NULL;
}
