#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <asm/prctl.h>
#include <sys/prctl.h>
#include "selector.h"


extern int arch_prctl(int code, unsigned long* addr);


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

void SegmentSelector_print(SegmentSelector_t selector)
{
    // index is 13 bits -> 2^13 = 8,192 -> 4 digits, hence %4d
    if ( 0 == selector.index )
            printf("index: %4d,  table indicator: -, rpl: -\n", 0);
    else
        printf("index: %4d,  table indicator: %d, rpl: %d\n", selector.index, selector.table_indicator, selector.rpl);
}

void SegmentSelector_get_and_print_CS()
{
    printf("        __ CS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_CS());
}

void SegmentSelector_get_and_print_SS()
{
    printf("        __ SS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_SS());
}

void SegmentSelector_get_and_print_DS()
{
    printf("        __ DS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_DS());
}

void SegmentSelector_get_and_print_ES()
{
    printf("        __ ES   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_ES());
}

void SegmentSelector_get_and_print_FS()
{
    printf("        __ FS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_FS());
}

void SegmentSelector_get_and_print_GS()
{
    printf("        __ GS   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_GS());
}

void SegmentSelector_get_and_print_TR()
{
    printf("        __ TR   <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_TR());
}

void SegmentSelector_get_and_print_LDTR()
{
    printf("        __ LDTR <SEL> = ");
    SegmentSelector_print(SegmentSelector_get_LDTR());
}

// output looks cleaner when not aligning to the maximum number of digits
// base is 64 bits -> 2^64 = 18,446,744,073,709,551,616 -> 28 digits

void SegmentSelector_get_and_print_FS_base()
{
    printf("        __ FS   <SLB> = %lu\n", SegmentSelector_get_FS_base());
}

void SegmentSelector_get_and_print_GS_base()
{
    printf("        __ GS   <SLB> = %lu\n", SegmentSelector_get_GS_base());
}