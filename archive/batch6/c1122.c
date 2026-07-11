#include <stdio.h>
struct Instruction{unsigned opcode:4;unsigned reg:4;unsigned immediate:8;};
static unsigned encode(struct Instruction i){return i.opcode|(i.reg<<4)|(i.immediate<<8);}
int main(void){struct Instruction i={3,2,127};printf("c1122 instruction=%u\n",encode(i));return 0;}
