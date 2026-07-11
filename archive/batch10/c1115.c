#include <stdio.h>
#include <stdint.h>

/* The word overlay assumes little-endian layout, shared by Z80 and the host. */
union Counters { uint16_t word; struct { unsigned rx:4;unsigned tx:4;unsigned retry:4;unsigned drop:4; }; };
static unsigned total(union Counters c){return c.rx+c.tx+c.retry+c.drop;}
int main(void){union Counters c={.rx=9,.tx=6,.retry=3,.drop=2};c.retry=(c.retry+5U)&15U;printf("c1115 counters=%u,%u,%04x\n",total(c),(unsigned)c.retry,(unsigned)c.word);return !(total(c)==25U&&c.retry==8U&&c.word==0x2869U);}
