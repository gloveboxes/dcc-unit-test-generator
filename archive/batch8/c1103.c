#include <stdio.h>
enum Op { OP_ADD, OP_SCALE };
struct Command { enum Op op; union { struct { int left,right; }; struct { int value,factor; }; }; };
static int execute(const struct Command *c){return c->op==OP_ADD?c->left+c->right:c->value*c->factor;}
int main(void){struct Command c={OP_SCALE,{.value=7,.factor=6}};int actual=execute(&c);printf("c1103 command=%d\n",actual);return actual!=42;}
