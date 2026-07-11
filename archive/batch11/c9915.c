#include <stdio.h>
#include <stdbool.h>
static bool valid_parens(int n, const char expr[n]) {
    int depth = 0;
    for (int i = 0; i < n; i++) {
        if (expr[i] == '(') depth++;
        else if (expr[i] == ')') { if (--depth < 0) return false; }
    }
    return depth == 0;
}
int main(void) {
    bool a = valid_parens(8, "((a+b))");
    bool b = valid_parens(5, "((())");
    printf("c9915 parens=%d,%d\n", (int)a, (int)b);
    return !(a && !b);
}
