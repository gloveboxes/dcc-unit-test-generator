#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
static bool check_packet(const uint8_t *data, int len) {
    if (len < 3) return false;
    uint8_t type = data[0];
    uint8_t payload_len = data[1];
    if (2 + payload_len + 1 != len) return false;
    uint8_t chk = type;
    for (int i = 0; i < payload_len; i++) chk ^= data[2 + i];
    return chk == data[len - 1];
}
int main(void) {
    uint8_t good[5] = {0x01, 0x02, 0xAA, 0xBB, 0x01^0xAA^0xBB};
    uint8_t bad[5]  = {0x01, 0x02, 0xAA, 0xBB, 0xFF};
    bool a = check_packet(good, 5), b = check_packet(bad, 5);
    printf("c9923 pkt=%d,%d\n", (int)a, (int)b);
    return !(a && !b);
}
