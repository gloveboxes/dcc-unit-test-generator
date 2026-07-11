#include <stdio.h>
struct MessagePkt{union{unsigned short hdr;struct{unsigned char id;unsigned char seq;};};};
int main(void){struct MessagePkt m={{0x0201}};printf("c1133 mpkt=%02x,%02x\n",m.id,m.seq);return 0;}
