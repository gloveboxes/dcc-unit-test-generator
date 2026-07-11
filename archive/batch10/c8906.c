#include <stdio.h>

struct Job { int id; int urgent; };

static int stable_partition(struct Job *a, int n)
{
    struct Job temp[8];
    int i, k, urgent;
    k = 0; urgent = 0;
    for (i = 0; i < n; ++i) if (a[i].urgent) { temp[k++] = a[i]; ++urgent; }
    for (i = 0; i < n; ++i) if (!a[i].urgent) temp[k++] = a[i];
    for (i = 0; i < n; ++i) a[i] = temp[i];
    return urgent;
}

int main(void)
{
    struct Job jobs[6] = {{10,0},{11,1},{12,0},{13,1},{14,1},{15,0}};
    int n, i;
    long signature;
    n = stable_partition(jobs, 6);
    signature = 0;
    for (i = 0; i < 6; ++i) signature = signature * 16L + (jobs[i].id - 10);
    printf("c8906 partition=%d,%ld\n", n, signature);
    return !(n == 3 && signature == 0x134025L);
}
