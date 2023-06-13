#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "selector.h"
#include "pseudo.h"
#include "segment.h"
#include "../threads/threads.h"

void _segment_info(pid_t(*get_id)())
{
    char* id_type = NULL;
    if ( get_id == &getpid )
        id_type = "pid_t";
    else if ( get_id == &gettid )
        id_type = "tid_t";
    else
    {
        fprintf(stderr, "Error: %s: %s: Invalid function pointer\n", __FILE__, __func__);
        exit(-1);
    }

    pid_t id = get_id();
    printf("%s: %-10d  --------------------------------------------------------\n", id_type, id);

    printf("%s: %d", id_type, id);
    SegmentSelector_print_CS();

    printf("%s: %d", id_type, id);
    SegmentSelector_print_SS();

    printf("%s: %d", id_type, id);
    SegmentSelector_print_DS();
    
    printf("%s: %d", id_type, id);
    SegmentSelector_print_ES();

    printf("%s: %d", id_type, id);
    SegmentSelector_print_FS();

    printf("%s: %d", id_type, id);
    SegmentSelector_print_GS();

    printf("%s: %d", id_type, id);
    SegmentSelector_print_TR();

    printf("%s: %d", id_type, id);
    SegmentSelector_print_LDTR();

    printf("%s: %d", id_type, id);
    PseudoDescriptor_print_GDTR();

    printf("%s: %d", id_type, id);
    PseudoDescriptor_print_IDTR();
}

void segment_info_pid()
{
    _segment_info(&getpid);
}

void segment_info_tid()
{
    _segment_info(&gettid);
}