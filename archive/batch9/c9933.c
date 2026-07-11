#include <stdio.h>
#include <stdint.h>
struct Header { uint8_t type; uint8_t flags; uint16_t length; };
struct Packet { struct Header header; uint16_t checksum; };
static const struct Packet packet={.checksum=0x55AAU,.header={.length=128U,.flags=3U,.type=7U}};
int main(void){printf("c9933 packet=%u,%u,%04x\n",(unsigned)packet.header.type,(unsigned)packet.header.length,(unsigned)packet.checksum);return !(packet.header.type==7U&&packet.header.length==128U&&packet.checksum==0x55AAU);}
