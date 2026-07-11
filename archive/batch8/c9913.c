#include <stdio.h>
typedef int (*Operation)(int, int);
static int add(int a, int b) { return a + b; } static int subtract(int a, int b) { return a - b; }
static const Operation operations[3] = {[0] = add, [2] = subtract};
int main(void) {
    int sum = operations[0](9, 4), difference = operations[2](9, 4);
    printf("c9913 dispatch=%d,%d\n", sum, difference); return !(sum == 13 && difference == 5);
}
