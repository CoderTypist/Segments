#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "selector.h"
#include "pseudo.h"
#include "segment.h"
#include "../threads/threads.h"


SegmentInfo_t* SegmentInfo_get()
{
    SegmentInfo_t* segment_info = (SegmentInfo_t*)calloc(1, sizeof(SegmentInfo_t));
    if( !segment_info )
    {
        fprintf(stderr, "Error: SegmentInfo_get(): calloc() failed for segment_info\n");
        exit(-1);
    }

    segment_info->cs_sel      = SegmentSelector_get_CS_sel();
    segment_info->ss_sel      = SegmentSelector_get_SS_sel();
    segment_info->ds_sel      = SegmentSelector_get_DS_sel();
    segment_info->es_sel      = SegmentSelector_get_ES_sel();
    segment_info->fs_sel      = SegmentSelector_get_FS_sel();
    segment_info->fs_base     = SegmentSelector_get_FS_base();
    segment_info->gs_sel      = SegmentSelector_get_GS_sel();
    segment_info->gs_base     = SegmentSelector_get_GS_base();
    segment_info->ldtr_sel    = SegmentSelector_get_LDTR_sel();
    segment_info->gdtr_pseudo = PseudoDescriptor_get_GDTR_pseudo();
    segment_info->idtr_pseudo = PseudoDescriptor_get_IDTR_pseudo();

    return segment_info;
}

void SegmentInfo_print(SegmentInfo_t* segment_info, PidType_t id_type)
{
    if( !segment_info )
    {
        fprintf(stderr, "Error: SegmentInfo_print(): segment_info is NULL\n");
        exit(-1);
    }

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


    printf("%s: %d        __ CS   <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->cs_sel);

    printf("%s: %d        __ SS   <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->ss_sel);
    
    printf("%s: %d        __ DS   <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->ds_sel);

    printf("%s: %d        __ ES   <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->es_sel);

    printf("%s: %d        __ FS   <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->fs_sel);

    printf("%s: %d        __ FS   <BSE> = ", id_type_as_str, id);
    SegmentBase_print(segment_info->fs_base);

    printf("%s: %d        __ GS   <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->gs_sel);

    printf("%s: %d        __ GS   <BSE> = ", id_type_as_str, id);
    SegmentBase_print(segment_info->gs_base);

    printf("%s: %d        __ TR   <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->tr_sel);

    printf("%s: %d        __ LDTR <SEL> = ", id_type_as_str, id);
    SegmentSelector_print(segment_info->ldtr_sel);

    printf("%s: %d        _  GDTR <PSD> = ", id_type_as_str, id);
    PseudoDescriptor_print(segment_info->gdtr_pseudo);

    printf("%s: %d        _  IDTR <PSD> = ", id_type_as_str, id);
    PseudoDescriptor_print(segment_info->idtr_pseudo);
}

void SegmentInfo_show(PidType_t id_type)
{
    SegmentInfo_t* segment_info = SegmentInfo_get();
    SegmentInfo_print(segment_info, id_type);
    free(segment_info);
}