#include <stdio.h>
#include <stdint.h>
static inline uint16_t ones_complement_sum(const uint16_t *data, int count) {
    uint32_t sum = 0;
    for (int i = 0; i < count; i++) sum += data[i];
    while (sum >> 16) sum = (sum & 0xFFFFU) + (sum >> 16);
    return (uint16_t)sum;
}
int main(void) {
    uint16_t data[4] = {0x1234U, 0x5678U, 0x9ABCU, 0xDEF0U};
    uint16_t s = ones_complement_sum(data, 4);
    printf("c9905 osum=%04x\n", (unsigned)s);
    return s != 0xE259U;
}
