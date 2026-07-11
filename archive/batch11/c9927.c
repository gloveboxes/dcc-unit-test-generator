#include <stdio.h>
#include <stdbool.h>
static bool can_jump(int n, const int jumps[n]) {
    int reach = 0;
    for (int i = 0; i <= reach && i < n; i++)
        if (i + jumps[i] > reach) reach = i + jumps[i];
    return reach >= n - 1;
}
int main(void) {
    int a[6] = {2, 3, 1, 1, 4, 0};
    int b[5] = {3, 2, 1, 0, 4};
    bool ra = can_jump(6, a), rb = can_jump(5, b);
    printf("c9927 jump=%d,%d\n", (int)ra, (int)rb);
    return !(ra && !rb);
}
