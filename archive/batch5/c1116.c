#include <stdio.h>
struct Token{enum{TOKEN_NUM,TOKEN_OP} kind;union{int number;char op;};};
int main(void){struct Token t={.kind=TOKEN_OP,.op='+'};printf("c1116 token=%d,%c\n",t.kind,t.op);return 0;}
