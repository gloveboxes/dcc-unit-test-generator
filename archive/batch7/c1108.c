#include <stdio.h>
struct Op{union{unsigned short val;struct{unsigned char op;unsigned char arg;};};};
int main(void){struct Op o={{0}};o.op=0x3e;o.arg=0x11;printf("c1108 op=%x\n",o.val);return 0;}
