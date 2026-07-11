#include <stdio.h>
#include <stdbool.h>
static int max_nested_depth(int n, const char expr[n]) {
    int depth = 0, max = 0;
    for (int i = 0; i < n; i++) {
        if (expr[i] == '(') { depth++; if (depth > max) max = depth; }
        else if (expr[i] == ')') depth--;
    }
    return max;
}
int main(void) {
    int a = max_nested_depth(11, "(a+(b*(c)))");
    int b = max_nested_depth(3,  "(x)");
    printf("c9931 depth=%d,%d\n", a, b);
    return !(a == 3 && b == 1);
}
