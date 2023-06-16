#include <stdio.h>
#include "pseudo.h"


void PseudoDescriptor_print(PseudoDescriptor_t pseudo)
{
    // base is 64 bits -> 2^16 = 18,446,744,073,709,551,616 -> 20 digits, hence %20d
    // limit is 16 bits -> 2^16 = 65,536 -> 5 digits, hence %5d
    // If UMIP is enabled, pseudo.limit will be zero
    if ( pseudo.limit == 0 )
        printf("base: %20s, limit: %5u\n", "-", pseudo.limit);
    else
        printf("base: %20lu, limit: %5u\n", pseudo.base, pseudo.limit);
}

// sgdt will not work because of UMIP
PseudoDescriptor_t PseudoDescriptor_get_GDTR_pseudo()
{
    PseudoDescriptor_t gdtr;
    asm volatile (
        "sgdt %[p_gdtr]\n"
        : [p_gdtr] "=m" (gdtr)
    );
    return gdtr;
}

// sidt will not work because of UMIP
PseudoDescriptor_t PseudoDescriptor_get_IDTR_pseudo()
{
    PseudoDescriptor_t idtr;
    asm volatile (
        "sidt %[p_idtr]\n"
        : [p_idtr] "=m" (idtr)
    );
    return idtr;
}
