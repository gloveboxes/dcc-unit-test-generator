#include <stdio.h>

static int binary(const int *a, int n, int key)
{
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void)
{
    int a[8] = {2, 5, 7, 11, 14, 18, 22, 31};
    printf("c8905 positions=%d,%d\n", binary(a, 8, 18), binary(a, 8, 9));
    return 0;
}
