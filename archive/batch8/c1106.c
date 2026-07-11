#include <stdio.h>
struct Register { union { unsigned char raw; struct { unsigned enabled:1; unsigned mode:2; unsigned pending:1; unsigned reserved:4; }; }; };
int main(void){struct Register r;r.raw=0;r.enabled=1;r.mode=3;r.pending=1;printf("c1106 register=%02x\n",r.raw);return r.raw!=0x0f;}
