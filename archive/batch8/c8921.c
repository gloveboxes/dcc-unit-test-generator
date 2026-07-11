#include <stdio.h>

#define COLS 8
static int edit_distance(const char *left, const char *right)
{
    int previous[COLS]; int current[COLS]; int i; int j; int cost; int best;
    int left_len = 0; int right_len = 0;
    while (left[left_len]) ++left_len; while (right[right_len]) ++right_len;
    if (right_len >= COLS) return -1;
    for (j = 0; j <= right_len; ++j) previous[j] = j;
    for (i = 1; i <= left_len; ++i) {
        current[0] = i;
        for (j = 1; j <= right_len; ++j) {
            cost = left[i-1] == right[j-1] ? 0 : 1;
            best = previous[j] + 1;
            if (current[j-1] + 1 < best) best = current[j-1] + 1;
            if (previous[j-1] + cost < best) best = previous[j-1] + cost;
            current[j] = best;
        }
        for (j = 0; j <= right_len; ++j) previous[j] = current[j];
    }
    return previous[right_len];
}

int main(void)
{
    int distance = edit_distance("kitten", "sitting");
    printf("c8921 edit=%d\n", distance);
    return distance != 3;
}
