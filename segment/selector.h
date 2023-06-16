#ifndef _SEGMENT_SELECTOR_H_
#define _SEGMENT_SELECTOR_H_


struct SegmentSelector
{
    unsigned int index : 13;
    unsigned int table_indicator : 1;
    unsigned int rpl : 2;
};
typedef struct SegmentSelector SegmentSelector_t;


SegmentSelector_t SegmentSelector_get_CS();
SegmentSelector_t SegmentSelector_get_SS();
SegmentSelector_t SegmentSelector_get_DS();
SegmentSelector_t SegmentSelector_get_ES();
SegmentSelector_t SegmentSelector_get_FS();
SegmentSelector_t SegmentSelector_get_GS();
SegmentSelector_t SegmentSelector_get_TR();
SegmentSelector_t SegmentSelector_get_LDTR();

typedef unsigned long SegmentBase_t;
SegmentBase_t SegmentSelector_get_FS_base();
SegmentBase_t SegmentSelector_get_GS_base();

void SegmentSelector_print(SegmentSelector_t selector);
void SegmentSelector_get_and_print_CS();
void SegmentSelector_get_and_print_SS();
void SegmentSelector_get_and_print_DS();
void SegmentSelector_get_and_print_ES();
void SegmentSelector_get_and_print_FS();
void SegmentSelector_get_and_print_GS();
void SegmentSelector_get_and_print_TR();
void SegmentSelector_get_and_print_LDTR();
void SegmentSelector_get_and_print_FS_base();
void SegmentSelector_get_and_print_GS_base();


#endif // _SEGMENT_SELECTOR_H_
