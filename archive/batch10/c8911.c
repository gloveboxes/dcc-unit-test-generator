#include <stdio.h>

static long spiral_sum(int a[4][4])
{
    int top, bottom, left, right, i;
    long sum;
    top = 0; bottom = 3; left = 0; right = 3; sum = 0;
    while (top <= bottom && left <= right) {
        for (i = left; i <= right; ++i) sum = sum * 3L + a[top][i]; ++top;
        for (i = top; i <= bottom; ++i) sum = sum * 3L + a[i][right]; --right;
        if (top <= bottom) { for (i = right; i >= left; --i) sum = sum * 3L + a[bottom][i]; --bottom; }
        if (left <= right) { for (i = bottom; i >= top; --i) sum = sum * 3L + a[i][left]; ++left; }
    }
    return sum;
}

int main(void)
{
    int grid[4][4] = {{1,0,2,1},{2,1,0,2},{0,2,1,0},{1,0,2,1}};
    long value;
    value = spiral_sum(grid);
    printf("c8911 spiral=%ld\n", value);
    return value != 18457016L;
}
