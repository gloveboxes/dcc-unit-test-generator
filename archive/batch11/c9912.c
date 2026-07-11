#include <stdio.h>
#include <stdint.h>
static inline uint32_t murmur_mix(uint32_t h, uint32_t k) {
    k = (uint32_t)(k * 0xCC9E2D51UL);
    k = (uint32_t)((k << 15) | (k >> 17));
    k = (uint32_t)(k * 0x1B873593UL);
    h ^= k;
    h = (uint32_t)((h << 13) | (h >> 19));
    return (uint32_t)(h * 5UL + 0xE6546B64UL);
}
int main(void) {
    uint32_t h = 0;
    uint32_t words[3] = {0x12345678UL, 0xABCDEF01UL, 0x55AA55AAUL};
    for (int i = 0; i < 3; i++) h = murmur_mix(h, words[i]);
    printf("c9912 mmix=%08lx\n", (unsigned long)h);
    return h == 0;
}
