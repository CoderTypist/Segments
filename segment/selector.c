#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <asm/prctl.h>
#include <sys/prctl.h>
#include "selector.h"


extern int arch_prctl(int code, unsigned long* addr);


void SegmentSelector_print(SegmentSelector_t selector)
{
    // index is 13 bits -> 2^13 = 8,192 -> 4 digits, hence %4d
    if ( 0 == selector.index )
            printf("index: %4d,  table indicator: -, rpl: -\n", 0);
    else
        printf("index: %4d,  table indicator: %d, rpl: %d\n", selector.index, selector.table_indicator, selector.rpl);
}

void SegmentBase_print(SegmentBase_t base)
{
    // output looks cleaner when not aligning to the maximum number of digits
    // base is 64 bits -> 2^64 = 18,446,744,073,709,551,616 -> 28 digits
    printf("%lu\n", base);
}

SegmentSelector_t SegmentSelector_get_CS_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %cs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_SS_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %ss, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_DS_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %ds, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_ES_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %es, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_FS_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %fs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_GS_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "mov %gs, %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_TR_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "str %ax\n"
    );
}

SegmentSelector_t SegmentSelector_get_LDTR_sel()
{
    asm volatile (
        "xor %rax, %rax\n"
        "sldt %ax\n"
    );
}

SegmentBase_t SegmentSelector_get_FS_base()
{
    unsigned long fs_base;
    if( -1 == arch_prctl(ARCH_GET_FS, &fs_base) )
    {
        perror("Error: SegmentSelector_get_FS_base(): Unable to access FS base");
        exit(-1);
    }
    return fs_base;
}

SegmentBase_t SegmentSelector_get_GS_base()
{
    unsigned long gs_base;
    if( -1 == arch_prctl(ARCH_GET_GS, &gs_base) )
    {
        perror("Error: SegmentSelector_get_GS_base(): Unable to access GS base");
        exit(-1);
    }
    return gs_base;
}