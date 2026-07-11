#include <stdio.h>
#include <stdbool.h>
static int water_trap(int n, const int height[n]) {
    int left_max[n], right_max[n];
    left_max[0] = height[0];
    for (int i = 1; i < n; i++)
        left_max[i] = height[i] > left_max[i-1] ? height[i] : left_max[i-1];
    right_max[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--)
        right_max[i] = height[i] > right_max[i+1] ? height[i] : right_max[i+1];
    int water = 0;
    for (int i = 0; i < n; i++) {
        int level = left_max[i] < right_max[i] ? left_max[i] : right_max[i];
        if (level > height[i]) water += level - height[i];
    }
    return water;
}
int main(void) {
    int h[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int w = water_trap(12, h);
    printf("c9929 water=%d\n", w);
    return w != 6;
}
