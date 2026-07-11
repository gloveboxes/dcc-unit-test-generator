#include <stdio.h>
enum TokenKind { TOKEN_NUMBER, TOKEN_OPERATOR };
struct Token { enum TokenKind kind; union { int number; char operator; }; };
static int apply(const struct Token *op,int left,int right){return op->operator=='+'?left+right:left*right;}
int main(void){struct Token token={.kind=TOKEN_OPERATOR,.operator='*'};int value=apply(&token,6,7);printf("c1110 token=%d,%c\n",value,token.operator);return !(value==42&&token.kind==TOKEN_OPERATOR);}
