#include "TemplateHacks.h"
#include <stdlib.h>
#include <stdio.h>

void testC()
{
    int three, minone, ran;
    double threedbl;
    puts("C");    
    three = AddFunctionInline(1, 2);
    minone = NegFunctionInline(1);
    srand(0);
    ran = RandFunctionInline();
    threedbl = AddDoubleFunctionInline(1.75654354, 1.24345646);
    puts("  want: 3 -1 38 3.000000");
    printf("  got : %d %d %d %f\n", three, minone, ran, threedbl);
}
