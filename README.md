# TemplateHacks

Utter template/macro hacks to achieve typesafety in messages sent over a C-interface. There is also C header compatibility so your messages will be callable from C (as long as you don't use C++ types).

This is what your message declarations will look like (`MessageTable.h`):

```
//Declare your messages here. Make sure that the last declaration doesn't have DEF_COMMA in the end.
DEF_MSG(MsgAdd, AddMsg, DEF_IMPL(int, add, int, int)) DEF_COMMA
DEF_STATIC(static int AddFunctionInline(int a, int b) { return DEF_SEND(MsgAdd, AddMsg, a, b); })
DEF_MSG(MsgNeg, NegMsg, DEF_IMPL(int, neg, int)) DEF_COMMA
DEF_STATIC(static int NegFunctionInline(int x) { return DEF_SEND(MsgNeg, NegMsg, x); })
DEF_MSG(MsgRand, RandMsg, DEF_IMPL(int, ran)) DEF_COMMA
DEF_STATIC(static int RandFunctionInline() { return DEF_SEND(MsgRand, RandMsg); })
DEF_MSG(MsgAddDouble, AddDoubleMsg, DEF_IMPL(double, addDouble, double, double))
DEF_STATIC(static double AddDoubleFunctionInline(double a, double b) { return DEF_SEND(MsgAddDouble, AddDoubleMsg, a, b); })
```

You declare the functions that handle your messages this way (`TemplateHacks.cpp`):

```
//Message implementations.
static int add(int a, int b) { return a + b; }
static int neg(int x) { return -x; }
static int ran() { return rand();  }
static double addDouble(double a, double b) { return a + b; }
```