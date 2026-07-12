#include <stdio.h>

static void merge(int *a, int *tmp, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi)
        tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= hi) tmp[k++] = a[j++];
    for (i = lo; i <= hi; ++i) a[i] = tmp[i];
}
static void sort(int *a, int *tmp, int lo, int hi)
{
    int mid;
    if (lo >= hi) return;
    mid = (lo + hi) / 2;
    sort(a, tmp, lo, mid); sort(a, tmp, mid + 1, hi); merge(a, tmp, lo, mid, hi);
}
int main(void)
{
    int a[7] = {9, 1, 5, 3, 3, 8, 2}, t[7], i;
    long sum = 0;
    sort(a, t, 0, 6);
    for (i = 0; i < 7; ++i) sum = sum * 10 + a[i];
    printf("c8901 sorted=%ld\n", sum);
    return 0;
}
