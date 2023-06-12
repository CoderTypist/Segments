#include <stdio.h>
#include "selector.h"


void SegmentSelector_print(SegmentSelector_t selector)
{
    // index is 13 bits -> 2^13 = 8192 -> 8192 is 4 digits/characters, hence %-4d
    if ( 0 == selector.index )
            printf("index: %-4d, table indicator: -, rpl: -\n", 0);
    else
        printf("index: %-4d, table indicator: %d, rpl: %d\n", selector.index, selector.table_indicator, selector.rpl);
}

SegmentSelector_t SegmentSelector_get_CS()
{
    asm (
        "xor %rax, %rax\n"
        "mov %cs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_SS()
{
    asm (
        "xor %rax, %rax\n"
        "mov %ss, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_DS()
{
    asm (
        "xor %rax, %rax\n"
        "mov %ds, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_ES()
{
    asm (
        "xor %rax, %rax\n"
        "mov %es, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_FS()
{
    asm (
        "xor %rax, %rax\n"
        "mov %fs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_GS()
{
    asm (
        "xor %rax, %rax\n"
        "mov %gs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_TR()
{
    asm(
        "xor %rax, %rax\n"
        "str %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_LDTR()
{
    asm(
        "xor %rax, %rax\n"
        "sldt %ax\n"
    );
}

SegmentSelector_t SegmentSelector_print_CS()
{
    printf("        CS   __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_CS());
}

SegmentSelector_t SegmentSelector_print_SS()
{
    printf("        SS   __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_SS());
}

SegmentSelector_t SegmentSelector_print_DS()
{
    printf("        DS   __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_DS());
}

SegmentSelector_t SegmentSelector_print_ES()
{
    printf("        ES   __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_ES());
}

SegmentSelector_t SegmentSelector_print_FS()
{
    printf("        FS   __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_FS());
}

SegmentSelector_t SegmentSelector_print_GS()
{
    printf("        GS   __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_GS());
}

SegmentSelector_t SegmentSelector_print_TR()
{
    printf("        TR   __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_TR());
}

SegmentSelector_t SegmentSelector_print_LDTR()
{
    printf("        LDTR __   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_LDTR());
}
