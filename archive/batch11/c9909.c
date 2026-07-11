#include <stdio.h>
#include <stdbool.h>
static bool all_unique(int n, const int values[n]) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (values[i] == values[j]) return false;
    return true;
}
int main(void) {
    int a[6] = {3,1,4,1,5,9};
    int b[6] = {2,7,1,8,2,8};
    int c[5] = {5,10,15,20,25};
    bool ra = all_unique(6, a), rb = all_unique(6, b), rc = all_unique(5, c);
    printf("c9909 unique=%d,%d,%d\n", (int)ra, (int)rb, (int)rc);
    return !(!ra && !rb && rc);
}
