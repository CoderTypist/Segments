#include <stdio.h>
#include "selector.h"


SegmentSelector_t SegmentSelector_get_CS()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %cs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_SS()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %ss, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_DS()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %ds, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_ES()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %es, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_FS()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %fs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_GS()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %gs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_TR()
{
    asm volatile (
        "xor %rax, %rax\n"
        "str %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_LDTR()
{
    asm volatile (
        "xor %rax, %rax\n"
        "sldt %ax\n"
    );
}

void SegmentSelector_print(SegmentSelector_t selector)
{
    // index is 13 bits -> 2^13 = 8,192 -> 4 digits, hence %4d
    if ( 0 == selector.index )
            printf("index: %4d,  table indicator: -, rpl: -\n", 0);
    else
        printf("index: %4d,  table indicator: %d, rpl: %d\n", selector.index, selector.table_indicator, selector.rpl);
}

SegmentSelector_t SegmentSelector_print_CS()
{
    printf("        __ CS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_CS());
}

SegmentSelector_t SegmentSelector_print_SS()
{
    printf("        __ SS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_SS());
}

SegmentSelector_t SegmentSelector_print_DS()
{
    printf("        __ DS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_DS());
}

SegmentSelector_t SegmentSelector_print_ES()
{
    printf("        __ ES   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_ES());
}

SegmentSelector_t SegmentSelector_print_FS()
{
    printf("        __ FS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_FS());
}

SegmentSelector_t SegmentSelector_print_GS()
{
    printf("        __ GS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_GS());
}

SegmentSelector_t SegmentSelector_print_TR()
{
    printf("        __ TR   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_TR());
}

SegmentSelector_t SegmentSelector_print_LDTR()
{
    printf("        __ LDTR <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_LDTR());
}
