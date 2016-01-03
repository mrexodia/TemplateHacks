//Included by other files.

#ifndef DEF_MSG
#define DEF_MSG(enumValue, typedefAlias, implementation)
#endif //DEF_MSG

#ifndef DEF_IMPL
#define DEF_IMPL(returnType, name, ...)
#endif //DEF_MSG

#ifndef DEF_COMMA
#define DEF_COMMA
#endif //DEF_COMMA

#ifndef DEF_STATIC
#define DEF_STATIC(function)
#endif //DEF_STATIC

#ifndef DEF_SEND
#ifdef __cplusplus
#define DEF_SEND(enumValue, typedefAlias, ...) typedefAlias::Send(__VA_ARGS__)
#else
#define DEF_SEND(enumValue, typedefAlias, ...) sendMessage(enumValue, __VA_ARGS__)
#endif //__cplusplus
#endif //DEF_SEND

//Declare your messages here. Make sure that the last declaration doesn't have DEF_COMMA in the end.
DEF_MSG(MsgAdd, AddMsg, DEF_IMPL(int, add, int, int)) DEF_COMMA
DEF_STATIC(static int AddFunctionInline(int a, int b) { return DEF_SEND(MsgAdd, AddMsg, a, b); })
DEF_MSG(MsgNeg, NegMsg, DEF_IMPL(int, neg, int)) DEF_COMMA
DEF_STATIC(static int NegFunctionInline(int x) { return DEF_SEND(MsgNeg, NegMsg, x); })
DEF_MSG(MsgRand, RandMsg, DEF_IMPL(int, ran)) DEF_COMMA
DEF_STATIC(static int RandFunctionInline() { return DEF_SEND(MsgRand, RandMsg); })
DEF_MSG(MsgAddDouble, AddDoubleMsg, DEF_IMPL(double, addDouble, double, double))
DEF_STATIC(static double AddDoubleFunctionInline(double a, double b) { return DEF_SEND(MsgAddDouble, AddDoubleMsg, a, b); })

#undef DEF_STATIC
#undef DEF_COMMA
#undef DEF_IMPL
#undef DEF_MSG