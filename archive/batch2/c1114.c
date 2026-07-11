#include <stdio.h>
enum Op{OP_ADD,OP_MUL,OP_END};
struct Instruction{enum Op op;union{struct{int left;int right;};int value;};};
int main(void){struct Instruction p[3]={{OP_ADD,{.left=2,.right=3}},{OP_MUL,{.left=0,.right=4}},{OP_END,{.value=0}}};printf("c1114 vm=%d/%d\n",p[0].left+p[0].right,p[1].right);return 0;}
