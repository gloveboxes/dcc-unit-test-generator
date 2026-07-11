#include <stdio.h>
static inline int clamp(int value, int low, int high) { return value < low ? low : value > high ? high : value; }
int main(void) {
    int a = clamp(-4, 0, 10), b = clamp(14, 0, 10), c = clamp(6, 0, 10);
    printf("c9908 clamp=%d,%d,%d\n", a, b, c); return !(a == 0 && b == 10 && c == 6);
}
