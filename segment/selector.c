#include <stdio.h>
#include "selector.h"


void SegmentSelector_hello()
{
    printf("SegmentSelector_hello()\n");
}

void SegmentSelector_print(SegmentSelector_t selector)
{
    // index is 13 bits -> 2^13 = 8192 -> 8192 is 4 digits/characters, hence %-4d
    printf("index: %-4d, table indicator: %d, rpl: %d\n", selector.index, selector.table_indicator, selector.rpl);
}

void SegmentSelector_print_all_registers()
{
    printf("        CS = ");
    SegmentSelector_print(SegmentSelector_get_CS());
    printf("        SS = ");
    SegmentSelector_print(SegmentSelector_get_SS());
    printf("        DS = ");
    SegmentSelector_print(SegmentSelector_get_DS());
    printf("        ES = ");
    SegmentSelector_print(SegmentSelector_get_ES());
    printf("        FS = ");
    SegmentSelector_print(SegmentSelector_get_FS());
    printf("        GS = ");
    SegmentSelector_print(SegmentSelector_get_GS());
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
