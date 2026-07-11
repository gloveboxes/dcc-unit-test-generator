#include <stdio.h>
#include <stdbool.h>
static bool is_strictly_sorted(int n, const int values[n]) {
    for (int i = 1; i < n; i++) if (values[i] <= values[i-1]) return false;
    return true;
}
int main(void) {
    int asc[5] = {1, 3, 5, 7, 9};
    int dup[5] = {1, 3, 3, 7, 9};
    int desc[4] = {9, 5, 3, 1};
    bool ra = is_strictly_sorted(5, asc);
    bool rb = is_strictly_sorted(5, dup);
    bool rc = is_strictly_sorted(4, desc);
    printf("c9921 sorted=%d,%d,%d\n", (int)ra, (int)rb, (int)rc);
    return !(ra && !rb && !rc);
}
