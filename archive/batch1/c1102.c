#include <stdio.h>

enum Kind { NUMBER, TEXT };
struct Value { enum Kind kind; union { int number; const char *text; }; };
int main(void)
{
    struct Value v = {NUMBER, {42}};
    printf("c1102 variant=%d\n", v.kind == NUMBER ? v.number : 0);
    return 0;
}
