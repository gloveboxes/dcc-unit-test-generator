#include <stdio.h>
struct Instruction { union { unsigned short raw; struct { unsigned opcode:4; unsigned target:4; unsigned operand:8; }; }; };
int main(void){struct Instruction i;i.raw=0;i.opcode=3;i.target=2;i.operand=127;printf("c1117 instruction=%04x\n",i.raw);return !(i.opcode==3&&i.target==2&&i.operand==127);}
