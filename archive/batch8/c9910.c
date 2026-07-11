#include <stdio.h>
#include <stdint.h>
static uint32_t checksum(const uint8_t *data, int count) {
    uint32_t hash = 2166136261UL; for (int i = 0; i < count; ++i) { hash ^= data[i]; hash *= 16777619UL; } return hash;
}
int main(void) {
    static const uint8_t data[] = {'Z','8','0'}; uint32_t actual = checksum(data, 3);
    printf("c9910 fnv=%lX\n", (unsigned long)actual); return actual != 0xD4D561CDUL;
}
