#include "TemplateHacks.h"

extern "C" void testC();

void testCpp()
{
    puts("C++");
    auto three = AddFunctionInline(1, 2);
    auto minone = NegFunctionInline(1);
    srand(0);
    auto ran = RandFunctionInline();
    auto threedbl = AddDoubleFunctionInline(1.75654354, 1.24345646);
    puts("  want: 3 -1 38 3.000000");
    printf("  got : %d %d %d %f\n", three, minone, ran, threedbl);
}