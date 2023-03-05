#ifndef _SEGMENT_SELECTOR_H_
#define _SEGMENT_SELECTOR_H_


struct SegmentSelector
{
    unsigned int index : 13;
    unsigned int table_indicator : 1;
    unsigned int rpl : 2;
};
typedef struct SegmentSelector SegmentSelector_t;


void SegmentSelector_hello();

void SegmentSelector_print(SegmentSelector_t selector);
void SegmentSelector_print_all_registers();
SegmentSelector_t SegmentSelector_get_CS();
SegmentSelector_t SegmentSelector_get_SS();
SegmentSelector_t SegmentSelector_get_DS();
SegmentSelector_t SegmentSelector_get_ES();
SegmentSelector_t SegmentSelector_get_FS();
SegmentSelector_t SegmentSelector_get_GS();

#endif // _SEGMENT_SELECTOR_H_
