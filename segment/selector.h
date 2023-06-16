#ifndef _SEGMENT_SELECTOR_H_
#define _SEGMENT_SELECTOR_H_


struct SegmentSelector
{
    unsigned int index : 13;
    unsigned int table_indicator : 1;
    unsigned int rpl : 2;
};
typedef struct SegmentSelector SegmentSelector_t;
typedef unsigned long SegmentBase_t;


void SegmentSelector_print(SegmentSelector_t selector);
void SegmentBase_print(SegmentBase_t base);

SegmentSelector_t SegmentSelector_get_CS_sel();
SegmentSelector_t SegmentSelector_get_SS_sel();
SegmentSelector_t SegmentSelector_get_DS_sel();
SegmentSelector_t SegmentSelector_get_ES_sel();
SegmentSelector_t SegmentSelector_get_FS_sel();
SegmentSelector_t SegmentSelector_get_GS_sel();
SegmentSelector_t SegmentSelector_get_TR_sel();
SegmentSelector_t SegmentSelector_get_LDTR_sel();

SegmentBase_t SegmentSelector_get_FS_base();
SegmentBase_t SegmentSelector_get_GS_base();

#endif // _SEGMENT_SELECTOR_H_
