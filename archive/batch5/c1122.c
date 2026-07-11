#include <stdio.h>
enum Kind{KIND_ADD,KIND_VALUE};
struct Instruction{enum Kind kind;union{struct{int left;int right;};int value;};};
int main(void){struct Instruction i={KIND_ADD,{.left=7,.right=8}};printf("c1122 instruction=%d\n",i.left+i.right);return 0;}
