#include <stdio.h>
#include <stdint.h>
static inline uint16_t fletcher16(const uint8_t *data, int len) {
    uint16_t s1 = 0, s2 = 0;
    for (int i = 0; i < len; i++) { s1 = (uint16_t)((s1 + data[i]) % 255U); s2 = (uint16_t)((s2 + s1) % 255U); }
    return (uint16_t)((s2 << 8) | s1);
}
int main(void) {
    static const uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint16_t ck = fletcher16(data, 5);
    printf("c9932 fletcher=%04x\n", (unsigned)ck);
    return ck != 0x230FU;
}
