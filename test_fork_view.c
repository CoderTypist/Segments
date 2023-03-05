#include <stdio.h>
#include <stdlib.h>

#include "./segment/selector.h"
#include "./segment/descriptor.h"

int main()
{
    printf("main()\n");
    SegmentSelector_hello();
    SegmentDescriptor_hello();
    SegmentSelector_print_all_registers();

    return 0;
}