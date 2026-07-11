#include <stdio.h>
enum InstructionKind{INS_LOAD,INS_ADD};
struct Instruction{enum InstructionKind kind;union{struct{int left;int right;};int constant;};};
int main(void){struct Instruction a={INS_LOAD,{.constant=6}};struct Instruction b={INS_ADD,{.left=4,.right=5}};printf("c1115 instruction=%d/%d,%d\n",a.constant,b.left,b.right);return 0;}
