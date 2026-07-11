#include <stdio.h>

int main(void)
{
    int a[10] = {0}, i, head = 0, tail = 0, value, total = 0;
    for (i = 1; i <= 6; ++i) { a[tail] = i * i; tail = (tail + 1) % 10; }
    while (head != tail) { value = a[head]; head = (head + 1) % 10; total += value; }
    printf("c8906 ring=%d\n", total);
    return 0;
}
