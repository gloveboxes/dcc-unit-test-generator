#include <stdio.h>
#include <stdint.h>
struct Opcode {
    union {
        struct { uint8_t op; uint8_t arg; };
        uint16_t word;
    };
};
static int execute(const struct Opcode *prog, int len, int *acc) {
    *acc = 0;
    for (int i = 0; i < len; i++) {
        if (prog[i].op == 0) *acc += prog[i].arg;
        else if (prog[i].op == 1) *acc -= prog[i].arg;
        else if (prog[i].op == 2) *acc *= prog[i].arg;
    }
    return *acc;
}
int main(void) {
    struct Opcode prog[4] = {{.op=0,.arg=10},{.op=0,.arg=5},{.op=2,.arg=3},{.op=1,.arg=7}};
    int acc;
    execute(prog, 4, &acc);
    printf("c1109 vm=%d,%04x\n", acc, (unsigned)prog[0].word);
    return acc != 38;
}
