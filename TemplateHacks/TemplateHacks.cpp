#include "TemplateHacks.h"

//message implementations
static int add(int a, int b)
{
    return a + b;
}

static int neg(int x)
{
    return -x;
}

static int ran()
{
    static auto n = 0;
    return n++;
}

//receiving message function
Result sendMessage(Message msg, ...)
{
    static const auto messageFunctions = std::make_tuple(
#define DEF_MESSAGE(enumValue, typedefAlias, function) typedefAlias(function)
#define DEF_FUNCTION(returnType, name, ...) name
#define DEF_COMMA ,
#define DEF_STATIC(x)
#include "MessageTable.h"
        );

    va_list vaList;
    va_start(vaList, msg);
    switch (msg)
    {
#define DEF_MESSAGE(enumValue, typedefAlias, function) \
    case enumValue: \
        return Result(std::get<enumValue>(messageFunctions).Receive(vaList));
#define DEF_FUNCTION(returnType, name, ...)
#define DEF_COMMA
#define DEF_STATIC(x)
#include "MessageTable.h"

    default:
        return DefaultResult;
    }
}