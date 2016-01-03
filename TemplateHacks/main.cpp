#include "TemplateHacks.h"

int main()
{
    auto three = AddMsg::send(1, 2); //shows (int, int) with autocompletion
    three = AddFunctionInline(1, 2); //shows (int a, int b) with autocompletion
    auto one = NegMsg::send(-1);
    one = NegFunctionInline(-1);
    auto ran = RandMsg::send();
    ran = RandFunctionInline();
    printf("%d %d %d\n", three, one, ran);
    getchar();
    return 0;
}