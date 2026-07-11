#include <stdio.h>
static const int codes[8] = {[1] = 100, [4] = 404, [7] = 700};
int main(void) {
    int total = codes[1] + codes[4] + codes[7];
    printf("c9902 sparse=%d,%d\n", total, codes[3]); return !(total == 1204 && codes[3] == 0);
}
