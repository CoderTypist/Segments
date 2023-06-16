#ifndef _PSEUDO_H_
#define _PSEUDO_H_


struct PseudoDescriptor
{
    unsigned short limit;
    unsigned long base;
} __attribute__((packed));
typedef struct PseudoDescriptor PseudoDescriptor_t;


void PseudoDescriptor_print(PseudoDescriptor_t pseudo);
PseudoDescriptor_t PseudoDescriptor_get_GDTR_pseudo();
PseudoDescriptor_t PseudoDescriptor_get_IDTR_pseudo();

#endif // _PSEUDO_H_