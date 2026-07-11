#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
enum MsgType { MSG_REQ, MSG_ACK, MSG_NAK };
struct Message {
    uint8_t seq;
    enum MsgType type;
    union {
        struct { uint8_t cmd; uint8_t payload[4]; };
        struct { uint8_t status; };
    };
};
static uint8_t msg_checksum(const struct Message *m) {
    uint8_t c = (uint8_t)((uint8_t)m->seq ^ (uint8_t)m->type);
    if (m->type == MSG_REQ) { c ^= m->cmd; for (int i=0;i<4;i++) c ^= m->payload[i]; }
    else c ^= m->status;
    return c;
}
int main(void) {
    struct Message req = {.seq=1,.type=MSG_REQ,.cmd=0x10U,.payload={1,2,3,4}};
    struct Message ack = {.seq=1,.type=MSG_ACK,.status=0};
    printf("c1133 msg=%02x,%02x\n", (unsigned)msg_checksum(&req), (unsigned)msg_checksum(&ack));
    return !(msg_checksum(&ack) == 0);
}
