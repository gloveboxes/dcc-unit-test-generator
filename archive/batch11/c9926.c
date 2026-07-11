#include <stdio.h>
#include <stdint.h>
static void hex_dump(const uint8_t *data, int len, char *out, int cap) {
    static const char hex[] = "0123456789ABCDEF";
    int pos = 0;
    for (int i = 0; i < len && pos + 2 < cap; i++) {
        out[pos++] = hex[data[i] >> 4];
        out[pos++] = hex[data[i] & 0x0FU];
    }
    out[pos] = '\0';
}
int main(void) {
    uint8_t data[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    char out[16];
    hex_dump(data, 4, out, 16);
    printf("c9926 hexdump=%s\n", out);
    return !(out[0]=='D' && out[1]=='E' && out[6]=='E' && out[7]=='F');
}
