#include <stdio.h>

enum TokenKind { TOKEN_INT, TOKEN_PLUS };
struct Token { enum TokenKind kind; union { int integer; char symbol; }; };
int main(void)
{
    struct Token stream[3] = {{TOKEN_INT, {8}}, {TOKEN_PLUS, {'+'}}, {TOKEN_INT, {5}}};
    printf("c1108 token=%d%c%d\n", stream[0].integer, stream[1].symbol, stream[2].integer);
    return 0;
}
