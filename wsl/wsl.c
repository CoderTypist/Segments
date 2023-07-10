#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "wsl.h"

#define VERSION_FILE "/proc/version"
#define MAX_LEN_VERSION_FILE 300
#define WSL_MAGIC "WSL"

bool wsl;

bool is_wsl()
{
    static bool previously_checked = false;
    static pthread_mutex_t mutex_previously_checked = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex_previously_checked);
    if( previously_checked )
    {
        pthread_mutex_unlock(&mutex_previously_checked);
        return wsl;
    }
    else
    {
        previously_checked = true;
    }
    pthread_mutex_unlock(&mutex_previously_checked);

    FILE* fp_version;
    if( NULL == (fp_version=fopen(VERSION_FILE, "r")) )
    {   
        fprintf(stderr, "Error: is_wsl(): Unable to open " VERSION_FILE "\n");
        exit(-1);
    }

    char version[MAX_LEN_VERSION_FILE] = { '\0' };
    if( NULL == fgets(version, MAX_LEN_VERSION_FILE, fp_version) )
    {
        fprintf(stderr, "Error: is_wsl(): Unable to read from " VERSION_FILE "\n");
        exit(-1);
    }

    if( version[MAX_LEN_VERSION_FILE-1] != '\0' )
    {
        fprintf(stderr, "Warning: is_wsl(): Length of " VERSION_FILE " exceeds MAX_LEN_VERSION_FILE\n");
        version[MAX_LEN_VERSION_FILE-1] = '\0';
    }

    return strstr(version, WSL_MAGIC) ? true : false;
}