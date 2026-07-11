#include <stdio.h>
enum TokenKind { TOKEN_NUMBER,TOKEN_OPERATOR };
struct Token { enum TokenKind kind; union { int number; char operation; }; };
static int token_score(const struct Token *t){return t->kind==TOKEN_NUMBER?t->number:(int)t->operation;}
int main(void){struct Token t={TOKEN_NUMBER,{.number=35}};int actual=token_score(&t);printf("c1113 token=%d\n",actual);return actual!=35;}
