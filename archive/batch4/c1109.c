#include <stdio.h>
struct Instruction{int opcode;union{struct{int left;int right;};int immediate;};};
static int execute(struct Instruction instruction){return instruction.opcode==1?instruction.left+instruction.right:instruction.immediate;}
int main(void){struct Instruction add={1,{.left=7,.right=8}},load={2,{.immediate=42}};printf("c1109 vm=%d,%d\n",execute(add),execute(load));return 0;}
