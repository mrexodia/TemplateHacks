#include "TemplateHacks.h"

//Message implementations.
static int add(int a, int b) { return a + b; }
static int neg(int x) { return -x; }
static int ran() { return rand();  }
static double addDouble(double a, double b) { return a + b; }

//Function that receives messages.
Result sendMessage(Message msg, ...)
{
    //Declare function implementation pointers.
    static const auto messageFunctions = std::make_tuple(
#define DEF_MSG(enumValue, typedefAlias, implementation) typedefAlias(implementation)
#define DEF_IMPL(returnType, name, ...) name
#define DEF_COMMA ,
#include "MessageTable.h"
        );

    //Call the appropriate function pointer for the switch case (needs continuous, zero based Message enum values).
    va_list vaList;
    va_start(vaList, msg);
    switch (msg)
    {
#define DEF_MSG(enumValue, typedefAlias, implementation) \
    case enumValue: \
        return Result(std::get<enumValue>(messageFunctions).Receive(vaList));
#include "MessageTable.h"

    default:
        return DefaultResult;
    }
}