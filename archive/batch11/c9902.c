#include <stdio.h>
#include <stdbool.h>
static bool is_power_of_two(unsigned int n) { return n > 0 && (n & (n - 1)) == 0; }
int main(void) {
    int yes = 0, no = 0;
    for (int i = 1; i <= 20; i++) {
        if (is_power_of_two((unsigned)i)) yes++; else no++;
    }
    printf("c9902 pow2=%d,%d\n", yes, no); /* 1,2,4,8,16 in 1..20 */
    return !(yes == 5 && no == 15);
}
