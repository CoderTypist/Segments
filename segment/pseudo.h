#ifndef _PSEUDO_H_
#define _PSEUDO_H_

struct PseudoDescriptor
{
    unsigned short limit;
    unsigned long base;
} __attribute__((packed));
typedef struct PseudoDescriptor PseudoDescriptor_t;

PseudoDescriptor_t PseudoDescriptor_get_GDTR();
PseudoDescriptor_t PseudoDescriptor_get_IDTR();
PseudoDescriptor_t PseudoDescriptor_print_GDTR();
PseudoDescriptor_t PseudoDescriptor_print_IDTR();

#endif // _PSEUDO_H_