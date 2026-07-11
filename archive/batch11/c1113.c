#include <stdio.h>
#include <stdint.h>
struct CanFrame {
    uint32_t id;
    uint8_t dlc;
    union {
        uint8_t data[8];
        struct { uint32_t word0; uint32_t word1; };
    };
};
int main(void) {
    struct CanFrame f = {.id=0x7FFU, .dlc=8};
    f.word0 = 0xDEADBEEFUL;
    f.word1 = 0xCAFEBABEUL;
    unsigned sum = 0;
    for (int i = 0; i < f.dlc; i++) sum += f.data[i];
    printf("c1113 can=%u,%02x\n", (unsigned)f.id, f.data[0]);
    return !(f.id == 0x7FFU && f.dlc == 8);
}
