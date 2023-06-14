#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "selector.h"
#include "pseudo.h"
#include "segment.h"
#include "../threads/threads.h"

void _segment_info(PidType_t id_type)
{
    pid_t id;
    char id_type_as_str[6];
    switch(id_type)
    {
        case PIDTYPE_PID:
            id = getpid();
            strcpy(id_type_as_str, "pid_t");
            break;
        case PIDTYPE_TID:
            id = gettid();
            strcpy(id_type_as_str, "tid_t");
            break;
        default:
            fprintf(stderr, "Error: _segment_info(): Unexpected value for PidType_t: %d\n", id_type);
            exit(-1);
    }
    
    printf("%s: %-10d --------------------------------------------------------\n", id_type_as_str, id);

    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_CS();

    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_SS();

    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_DS();
    
    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_ES();

    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_FS();

    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_GS();

    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_TR();

    printf("%s: %d", id_type_as_str, id);
    SegmentSelector_print_LDTR();

    printf("%s: %d", id_type_as_str, id);
    PseudoDescriptor_print_GDTR();

    printf("%s: %d", id_type_as_str, id);
    PseudoDescriptor_print_IDTR();
}

void segment_info_pid()
{
    _segment_info(PIDTYPE_PID);
}

void segment_info_tid()
{
    _segment_info(PIDTYPE_TID);
}