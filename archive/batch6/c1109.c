#include <stdio.h>
struct Command{enum{CMD_ADD,CMD_SUB} op;struct{int left;int right;};};
static int execute(struct Command c){return c.op==CMD_ADD?c.left+c.right:c.left-c.right;}
int main(void){struct Command c={CMD_SUB,{17,5}};printf("c1109 command=%d\n",execute(c));return 0;}
