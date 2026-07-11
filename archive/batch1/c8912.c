#include <stdio.h>

int main(void)
{
    int stack[16], top = 0, i, value, result = 0;
    const char *expr = "23*54*+9-";
    for (i = 0; expr[i] != '\0'; ++i) {
        if (expr[i] >= '0' && expr[i] <= '9') stack[top++] = expr[i] - '0';
        else { value = stack[--top];
            if (expr[i] == '+') stack[top - 1] += value;
            if (expr[i] == '-') stack[top - 1] -= value;
            if (expr[i] == '*') stack[top - 1] *= value;
        }
    }
    result = stack[0];
    printf("c8912 rpn=%d\n", result);
    return 0;
}
