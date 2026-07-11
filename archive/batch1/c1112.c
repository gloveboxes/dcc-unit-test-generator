#include <stdio.h>

enum Op { OP_ADD, OP_MUL, OP_HALT };
struct Instruction { enum Op op; union { struct { int left; int right; }; int value; }; };
int main(void)
{
    struct Instruction program[3] = {{OP_ADD, {.left = 2, .right = 3}}, {OP_MUL, {.left = 0, .right = 4}}, {OP_HALT, {.value = 0}}};
    int accumulator = program[0].left + program[0].right;
    accumulator *= program[1].right;
    printf("c1112 vm=%d/%d\n", accumulator, program[2].op);
    return 0;
}
