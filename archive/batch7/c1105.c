#include <stdio.h>
struct MsgHdr{unsigned type:4;unsigned id:4;unsigned len:8;};
static unsigned encode_hdr(struct MsgHdr h){return h.type|(h.id<<4)|(h.len<<8);}
int main(void){printf("c1105 hdr=%x\n",encode_hdr((struct MsgHdr){2,5,30}));return 0;}
