#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include <sys/types.h>
#include "selector.h"
#include "pseudo.h"
#include "../pid/pid.h"


struct SegmentInfo
{
    SegmentSelector_t cs_sel;
    SegmentSelector_t ss_sel;
    SegmentSelector_t ds_sel;
    SegmentSelector_t es_sel;
    SegmentSelector_t fs_sel;
    SegmentBase_t fs_base;
    SegmentSelector_t gs_sel;
    SegmentBase_t gs_base;
    SegmentSelector_t tr_sel;
    SegmentSelector_t ldtr_sel;
    PseudoDescriptor_t gdtr_pseudo;
    PseudoDescriptor_t idtr_pseudo;
};
typedef struct SegmentInfo SegmentInfo_t;


SegmentInfo_t* SegmentInfo_get();
void SegmentInfo_print(SegmentInfo_t* segment_info, PidType_t id_type);
void SegmentInfo_show(PidType_t id_type);

#endif // _SEGMENT_H_