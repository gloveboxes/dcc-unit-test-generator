#include <stdio.h>
struct Instruction{unsigned op:4;unsigned rd:4;unsigned rs:4;unsigned rt:4;};
static unsigned assemble(struct Instruction i){return i.op|(i.rd<<4)|(i.rs<<8)|(i.rt<<12);}
int main(void){printf("c1119 ins=%04x\n",assemble((struct Instruction){1,2,3,4}));return 0;}
