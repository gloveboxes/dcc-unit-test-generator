#include <stdio.h>

int main(void)
{
    int a[4] = {1, 2, 3, 4}, i, j, temp, checksum = 0;
    for (i = 3; i > 0; --i) { j = (i * 7 + 1) % (i + 1); temp = a[i]; a[i] = a[j]; a[j] = temp; }
    for (i = 0; i < 4; ++i) checksum = checksum * 10 + a[i];
    printf("c9916 shuffle=%d\n", checksum);
    return 0;
}
