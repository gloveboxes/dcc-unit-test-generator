#include <stdio.h>

int main(void)
{
    int data[5] = {4, 1, 7, 2, 9}, i, j, key;
    for (i = 1; i < 5; ++i) { key = data[i]; j = i - 1; while (j >= 0 && data[j] > key) { data[j + 1] = data[j]; --j; } data[j + 1] = key; }
    printf("c9915 insertion=%d%d%d%d%d\n", data[0], data[1], data[2], data[3], data[4]);
    return 0;
}
