#ifndef TEMPLATE_HACKS_H
#define TEMPLATE_HACKS_H

#include <stdarg.h>

#ifdef __cplusplus
#include <functional>
#endif //__cplusplus

//Define possible messages.
enum Message
{
#define DEF_MESSAGE(enumValue, typedefAlias, function) enumValue
#define DEF_COMMA ,
#include "MessageTable.h"
};

//Define message receiver return type.
typedef int Result;
static const Result DefaultResult = 0;

extern "C" Result sendMessage(Message msg, ...);

#ifdef __cplusplus
template<Message M, typename R, typename... P>
class Msg
{
public:
    typedef R(*Receiver)(P...); //std::function<R(P...)> Receiver; //generates a SHITLOAD of bloat with performance penalties

    explicit Msg(Receiver receiver)
        : receiver(receiver)
    {
    }

    static R Send(P... params)
    {
        return R(sendMessage(M, std::forward<P>(params)...));
    }

    R Receive(va_list & vaList) const
    {
        auto result = receiver(std::forward<P>(getArg<P>(vaList))...);
        va_end(vaList);
        return result;
    }

private:
    Receiver receiver;

    template<typename T>
    T getArg(va_list & vaList) const
    {
        return va_arg(vaList, T);
    }
};

//Typedef Msg types
#define DEF_MESSAGE(enumValue, typedefAlias, implementation) typedef Msg<enumValue, implementation> typedefAlias;
#define DEF_IMPLEMENTATION(returnType, name, ...) returnType, __VA_ARGS__
#include "MessageTable.h"
#endif //__cplusplus

//Declare static implemetation functions.
#define DEF_STATIC(x) x
#include "MessageTable.h"

#endif //TEMPLATE_HACKS_H