#include "TemplateHacks.h"
#include <stdlib.h>
#include <stdio.h>

void testC()
{
    puts("C");
    int three, minone, ran;
    three = AddFunctionInline(1, 2);
    minone = NegFunctionInline(1);
    srand(0);
    ran = RandFunctionInline();
    puts("  want: 3 -1 38");
    printf("  got : %d %d %d\n", three, minone, ran);
}
