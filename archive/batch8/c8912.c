#include <stdio.h>

static int median_from_histogram(const int counts[], int bins)
{
    int total = 0; int target; int seen = 0; int i;
    for (i = 0; i < bins; ++i) total += counts[i];
    target = total / 2;
    for (i = 0; i < bins; ++i) {
        seen += counts[i];
        if (seen > target) return i;
    }
    return -1;
}

int main(void)
{
    static const int counts[] = {0, 2, 1, 4, 2, 0};
    int median = median_from_histogram(counts, 6);
    printf("c8912 median=%d\n", median);
    return median != 3;
}
