#include <stdio.h>
enum OperandKind { IMMEDIATE, ADDRESS };
struct Instruction { int opcode; enum OperandKind kind; union { int immediate; unsigned address; }; };
static int execute(const struct Instruction *instruction,int accumulator){return instruction->kind==IMMEDIATE?accumulator+instruction->immediate:accumulator+(int)instruction->address;}
int main(void){struct Instruction instruction={.opcode=1,.kind=IMMEDIATE,.immediate=-7};int result=execute(&instruction,20);printf("c1106 instruction=%d,%d\n",result,instruction.opcode);return !(result==13&&instruction.opcode==1);}
