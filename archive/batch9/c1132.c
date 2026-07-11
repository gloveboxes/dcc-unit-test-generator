#include <stdio.h>
enum ExprKind { EXPR_VALUE, EXPR_BINARY };
struct Expr { enum ExprKind kind; union { int value; struct { char op; int left,right; }; }; };
static int evaluate(const struct Expr *expr){if(expr->kind==EXPR_VALUE)return expr->value;return expr->op=='+'?expr->left+expr->right:expr->left*expr->right;}
int main(void){struct Expr expression={.kind=EXPR_BINARY,.op='+',.left=19,.right=23};printf("c1132 expression=%d\n",evaluate(&expression));return evaluate(&expression)!=42;}
