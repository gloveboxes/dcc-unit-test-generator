#include <stdio.h>

static int maximum_subarray(const int values[], int count)
{
    int best = values[0]; int ending = values[0]; int i;
    for (i = 1; i < count; ++i) {
        ending = ending + values[i] > values[i] ? ending + values[i] : values[i];
        if (ending > best) best = ending;
    }
    return best;
}

int main(void)
{
    static const int values[] = {-2, 3, -1, 5, -6, 4};
    int best = maximum_subarray(values, 6);
    printf("c8922 kadane=%d\n", best);
    return best != 7;
}
