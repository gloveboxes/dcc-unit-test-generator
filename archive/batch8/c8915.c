#include <stdio.h>

#define WIDTH 3
static void multiply(const int left[WIDTH][WIDTH], const int right[WIDTH][WIDTH],
                     int result[WIDTH][WIDTH])
{
    int row; int column; int k; int sum;
    for (row = 0; row < WIDTH; ++row)
        for (column = 0; column < WIDTH; ++column) {
            sum = 0;
            for (k = 0; k < WIDTH; ++k) sum += left[row][k] * right[k][column];
            result[row][column] = sum;
        }
}

int main(void)
{
    static const int a[WIDTH][WIDTH] = {{1,2,0},{0,1,3},{2,0,1}};
    static const int b[WIDTH][WIDTH] = {{2,0,1},{1,1,0},{0,2,1}};
    int result[WIDTH][WIDTH]; multiply(a, b, result);
    printf("c8915 matrix=%d,%d\n", result[0][0], result[1][2]);
    return !(result[0][0] == 4 && result[1][2] == 3);
}
