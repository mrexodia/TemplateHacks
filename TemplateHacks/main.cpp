#include <cstdio>

void testCpp();
extern "C" void testC();

int main()
{
    testCpp();
    testC();
    getchar();
    return 0;
}