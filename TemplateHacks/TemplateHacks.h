#ifndef TEMPLATE_HACKS_H
#define TEMPLATE_HACKS_H

#include <stdarg.h>

#ifdef __cplusplus
#include <functional>
#endif //__cplusplus

enum Message
{
#define DEF_COMMA ,
#define DEF_FUNCTION
#define DEF_MESSAGE(enumValue, typedefAlias, function) enumValue
#include "MessageTable.h"
#undef DEF_MESSAGE
#undef DEF_FUNCTION
#undef DEF_COMMA
};

typedef int Result;
static const Result DefaultResult = 0;
typedef int Param;

extern "C" Result sendMessage(Message msg, ...);

template<Message M, typename R, typename... P>
class Msg
{
public:
    typedef std::function<R(P...)> Receiver;

    explicit Msg(Receiver receiver)
        : receiver(receiver)
    {
    }

    static R send(P... params)
    {
        return R(sendMessage(M, params...));
    }

    template<typename T>
    T getArg(va_list & vaList) const
    {
        return va_arg(vaList, T);
    }

    R receive(va_list & vaList) const
    {
        auto result = receiver(getArg<P>(vaList)...);
        va_end(vaList);
        return result;
    }

private:
    Receiver receiver;
};

#ifdef __cplusplus
#define DEF_COMMA
#define DEF_FUNCTION(returnType, name, ...) returnType, __VA_ARGS__
#define DEF_MESSAGE(enumValue, typedefAlias, function) typedef Msg<enumValue, function> typedefAlias;
#include "MessageTable.h"
#undef DEF_MESSAGE
#undef DEF_FUNCTION
#undef DEF_COMMA

#undef DEF_STATIC
#define DEF_STATIC(x) x
#include "MessageTable.h"
#undef DEF_STATIC
#undef DEF_COMMA
#undef DEF_FUNCTION
#undef DEF_MESSAGE
#endif //__cplusplus

#endif //TEMPLATE_HACKS_H