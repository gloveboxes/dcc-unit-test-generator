#include <stdio.h>

struct Interval { int first; int last; };

static int merge_intervals(const struct Interval input[], int count,
                           struct Interval output[])
{
    int i;
    int used = 0;
    for (i = 0; i < count; ++i) {
        if (used == 0 || input[i].first > output[used - 1].last + 1) {
            output[used++] = input[i];
        } else if (input[i].last > output[used - 1].last) {
            output[used - 1].last = input[i].last;
        }
    }
    return used;
}

int main(void)
{
    static const struct Interval input[] = {{1,3}, {3,7}, {9,10}, {11,14}};
    struct Interval output[4];
    int used = merge_intervals(input, 4, output);
    printf("c8905 merge=%d,%d-%d,%d-%d\n", used,
           output[0].first, output[0].last, output[1].first, output[1].last);
    return !(used == 2 && output[0].last == 7 && output[1].last == 14);
}
