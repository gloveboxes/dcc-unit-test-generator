#include <stdio.h>
#include <stdint.h>
struct GPIO {
    union {
        struct { uint8_t output; uint8_t direction; uint8_t pullup; uint8_t reserved; };
        uint32_t word;
    };
};
int main(void) {
    struct GPIO port = {.output=0x00U, .direction=0xFFU, .pullup=0xAAU, .reserved=0};
    port.output = 0x55U;
    port.direction &= 0x0FU;
    printf("c1132 gpio=%02x,%02x\n", (unsigned)port.output, (unsigned)port.direction);
    return !(port.output==0x55U && port.direction==0x0FU);
}
