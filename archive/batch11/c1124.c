#include <stdio.h>
#include <stdbool.h>
struct Matrix2x2 {
    union {
        struct { int a, b, c, d; };
        int m[4];
    };
};
static struct Matrix2x2 mat_mul(const struct Matrix2x2 *x, const struct Matrix2x2 *y) {
    return (struct Matrix2x2){
        .a = x->a*y->a + x->b*y->c,
        .b = x->a*y->b + x->b*y->d,
        .c = x->c*y->a + x->d*y->c,
        .d = x->c*y->b + x->d*y->d
    };
}
int main(void) {
    struct Matrix2x2 A = {.a=1,.b=2,.c=3,.d=4};
    struct Matrix2x2 B = {.a=5,.b=6,.c=7,.d=8};
    struct Matrix2x2 C = mat_mul(&A, &B);
    printf("c1124 mat=%d,%d,%d,%d\n", C.a, C.b, C.c, C.d);
    return !(C.a==19 && C.b==22 && C.c==43 && C.d==50);
}
