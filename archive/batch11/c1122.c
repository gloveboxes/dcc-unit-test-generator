#include <stdio.h>
#include <stdbool.h>
enum TokenKind { TOK_NUM, TOK_OP, TOK_END };
struct Token {
    enum TokenKind kind;
    union {
        int number;
        char op;
    };
};
static int simple_eval(const struct Token *toks, int n) {
    int result = toks[0].number;
    for (int i = 1; i + 1 < n; i += 2) {
        int next = toks[i+1].number;
        if (toks[i].op == '+') result += next;
        else if (toks[i].op == '-') result -= next;
        else if (toks[i].op == '*') result *= next;
    }
    return result;
}
int main(void) {
    struct Token prog[5] = {
        {.kind=TOK_NUM,.number=3},
        {.kind=TOK_OP, .op='+'},
        {.kind=TOK_NUM,.number=4},
        {.kind=TOK_OP, .op='*'},
        {.kind=TOK_NUM,.number=2}
    };
    int r = simple_eval(prog, 5);
    printf("c1122 eval=%d\n", r);
    return r != 14;
}
