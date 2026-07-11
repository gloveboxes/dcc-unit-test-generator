#include <stdio.h>
#include <stdbool.h>
enum NodeKind { NVAL, NADD, NMUL };
struct Expr {
    enum NodeKind kind;
    union {
        int value;
        struct { int left; int right; };
    };
};
static int eval(const struct Expr *e) {
    if (e->kind == NVAL) return e->value;
    if (e->kind == NADD) return e->left + e->right;
    return e->left * e->right;
}
int main(void) {
    struct Expr mul = {.kind=NMUL, .left=6, .right=7};
    struct Expr val = {.kind=NVAL, .value=100};
    printf("c1104 expr=%d,%d\n", eval(&mul), eval(&val));
    return !(eval(&mul)==42 && eval(&val)==100);
}
