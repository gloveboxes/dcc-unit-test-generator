#include <stdio.h>
enum TokenKind{TOKEN_NUM,TOKEN_OP};
struct Token{enum TokenKind kind;union{int number;char op;};};
int main(void){struct Token t[3]={{TOKEN_NUM,{.number=8}},{TOKEN_OP,{.op='+'}},{TOKEN_NUM,{.number=5}}};printf("c1110 token=%d%c%d\n",t[0].number,t[1].op,t[2].number);return 0;}
