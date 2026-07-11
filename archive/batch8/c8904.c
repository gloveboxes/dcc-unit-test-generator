#include <stdio.h>

static int lower_bound(const int values[], int count, int target)
{
    int first = 0;
    int length = count;
    int half;
    int middle;
    while (length > 0) {
        half = length / 2;
        middle = first + half;
        if (values[middle] < target) {
            first = middle + 1;
            length -= half + 1;
        } else {
            length = half;
        }
    }
    return first;
}

int main(void)
{
    static const int values[] = {2, 4, 4, 4, 9, 12};
    int at4 = lower_bound(values, 6, 4);
    int at7 = lower_bound(values, 6, 7);
    printf("c8904 lower=%d,%d\n", at4, at7);
    return !(at4 == 1 && at7 == 4);
}
