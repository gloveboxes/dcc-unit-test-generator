#include <stdio.h>
struct Config { int rows, columns, enabled; };
static int cells(struct Config value) { return value.enabled ? value.rows * value.columns : 0; }
int main(void) {
    struct Config value = {.columns = 80, .enabled = 1, .rows = 25};
    int actual = cells(value); printf("c9901 config=%d\n", actual); return actual != 2000;
}
