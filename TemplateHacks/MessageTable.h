//Included by other files.

#ifndef DEF_MESSAGE
#define DEF_MESSAGE(enumValue, typedefAlias, implementation)
#endif //DEF_MESSAGE

#ifndef DEF_IMPLEMENTATION
#define DEF_IMPLEMENTATION(returnType, name, ...)
#endif //DEF_MESSAGE

#ifndef DEF_COMMA
#define DEF_COMMA
#endif //DEF_COMMA

#ifndef DEF_STATIC
#define DEF_STATIC(x)
#endif //DEF_STATIC

#ifndef DEF_SEND
#ifdef __cplusplus
#define DEF_SEND(enumValue, typedefAlias, ...) typedefAlias::Send(__VA_ARGS__)
#else
#define DEF_SEND(enumValue, typedefAlias, ...) sendMessage(enumValue, __VA_ARGS__)
#endif //__cplusplus
#endif //DEF_SEND

DEF_MESSAGE(MsgAdd, AddMsg, DEF_IMPLEMENTATION(int, add, int, int)) DEF_COMMA
DEF_STATIC(static int AddFunctionInline(int a, int b) { return DEF_SEND(MsgAdd, AddMsg, a, b); })
DEF_MESSAGE(MsgNeg, NegMsg, DEF_IMPLEMENTATION(int, neg, int)) DEF_COMMA
DEF_STATIC(static int NegFunctionInline(int x) { return DEF_SEND(MsgNeg, NegMsg, x); })
DEF_MESSAGE(MsgRand, RandMsg, DEF_IMPLEMENTATION(int, ran))
DEF_STATIC(static int RandFunctionInline() { return DEF_SEND(MsgRand, RandMsg); })

#undef DEF_STATIC
#undef DEF_COMMA
#undef DEF_IMPLEMENTATION
#undef DEF_MESSAGE