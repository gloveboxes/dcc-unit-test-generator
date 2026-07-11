#include <stdio.h>
static int histogram_mode(int count, const int values[count], int bins) {
    int frequency[bins]; for (int i = 0; i < bins; ++i) frequency[i] = 0;
    for (int i = 0; i < count; ++i) ++frequency[values[i]];
    int best = 0; for (int i = 1; i < bins; ++i) if (frequency[i] > frequency[best]) best = i; return best;
}
int main(void) { int values[7] = {2,1,3,2,4,2,1}; int mode = histogram_mode(7, values, 5); printf("c9911 mode=%d\n", mode); return mode != 2; }
