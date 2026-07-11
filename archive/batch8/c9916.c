#include <stdio.h>
#include <stdbool.h>
static bool balanced(const char *text) {
    int depth=0; for (;*text;++text) { if (*text=='(') ++depth; else if (*text==')' && --depth<0) return false; } return depth==0;
}
int main(void) { bool a=balanced("(a+(b))"), b=balanced("(()"); printf("c9916 balanced=%d,%d\n",(int)a,(int)b); return !(a && !b); }
