#include <stdio.h>
static int histogram(int count, const int values[count], int buckets[], int nbuckets, int lo, int hi) {
    for (int i = 0; i < nbuckets; i++) buckets[i] = 0;
    int width = (hi - lo + nbuckets - 1) / nbuckets;
    for (int i = 0; i < count; i++) {
        int idx = (values[i] - lo) / width;
        if (idx >= 0 && idx < nbuckets) buckets[idx]++;
    }
    return width;
}
int main(void) {
    int values[10] = {2,5,8,11,14,3,9,13,6,10};
    int buckets[4];
    histogram(10, values, buckets, 4, 0, 16);
    printf("c9914 hist=%d,%d\n", buckets[0], buckets[3]);
    return !(buckets[0] == 2 && buckets[3] == 2);
}
