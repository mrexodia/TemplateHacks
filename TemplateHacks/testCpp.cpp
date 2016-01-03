#include "TemplateHacks.h"

extern "C" void testC();

void testCpp()
{
    puts("C++");
    auto three = AddFunctionInline(1, 2);
    auto minone = NegFunctionInline(1);
    srand(0);
    auto ran = RandFunctionInline();
    puts("  want: 3 -1 38");
    printf("  got : %d %d %d\n", three, minone, ran);
}