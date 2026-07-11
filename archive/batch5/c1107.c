#include <stdio.h>
struct Command{int opcode;union{struct{int left;int right;};int immediate;};};
int main(void){struct Command c={.opcode=1,.left=7,.right=5};printf("c1107 command=%d,%d\n",c.opcode,c.left+c.right);return 0;}
