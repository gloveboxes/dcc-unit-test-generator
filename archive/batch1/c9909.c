#include <stdio.h>

int main(void)
{
    char text[32];
    int used = sprintf(text, "%s:%d:%X", "node", 42, 42);
    printf("c9909 formatted=%s/%d\n", text, used);
    return 0;
}
