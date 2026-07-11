#include <stdio.h>

static int evaluate_rpn(const char *tokens[], int count, int *result)
{
    int stack[8]; int top = 0; int i; int left; int right;
    for (i = 0; i < count; ++i) {
        if (tokens[i][1] == '\0' && (tokens[i][0] == '+' || tokens[i][0] == '*')) {
            if (top < 2) return 0;
            right = stack[--top]; left = stack[--top];
            stack[top++] = tokens[i][0] == '+' ? left + right : left * right;
        } else {
            if (top == 8) return 0;
            stack[top++] = tokens[i][0] - '0';
        }
    }
    if (top != 1) return 0;
    *result = stack[0]; return 1;
}

int main(void)
{
    static const char *tokens[] = {"2", "3", "+", "4", "*"};
    int result = 0; int ok = evaluate_rpn(tokens, 5, &result);
    printf("c8911 rpn=%d,%d\n", ok, result);
    return !(ok && result == 20);
}
