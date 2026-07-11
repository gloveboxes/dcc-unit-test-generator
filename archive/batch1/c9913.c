#include <stdbool.h>
#include <stdio.h>

static bool balanced(const char *s)
{
    int depth = 0, i;
    for (i = 0; s[i] != '\0'; ++i) { if (s[i] == '(') ++depth; if (s[i] == ')' && --depth < 0) return false; }
    return depth == 0;
}
int main(void)
{
    printf("c9913 balanced=%d/%d\n", balanced("(()())"), balanced("())("));
    return 0;
}
