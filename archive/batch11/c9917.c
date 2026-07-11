#include <stdio.h>
#include <stdbool.h>
static bool all_satisfy(int n, const int values[n], bool (*pred)(int)) {
    for (int i = 0; i < n; i++) if (!pred(values[i])) return false;
    return true;
}
static bool positive(int v) { return v > 0; }
static bool nonzero(int v) { return v != 0; }
int main(void) {
    int a[5] = {3, 1, 4, 1, 5};
    int b[4] = {2, -1, 4, 7};
    bool r1 = all_satisfy(5, a, positive);
    bool r2 = all_satisfy(4, b, positive);
    bool r3 = all_satisfy(4, b, nonzero);
    printf("c9917 pred=%d,%d,%d\n", (int)r1, (int)r2, (int)r3);
    return !(r1 && !r2 && r3);
}
