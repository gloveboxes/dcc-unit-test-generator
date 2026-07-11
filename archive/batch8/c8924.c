#include <stdio.h>

#define SIZE 3
static void transpose(int matrix[SIZE][SIZE])
{
    int row; int column; int value;
    for (row = 0; row < SIZE; ++row)
        for (column = row + 1; column < SIZE; ++column) {
            value = matrix[row][column];
            matrix[row][column] = matrix[column][row];
            matrix[column][row] = value;
        }
}

int main(void)
{
    int matrix[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
    transpose(matrix);
    printf("c8924 transpose=%d,%d\n", matrix[0][2], matrix[2][0]);
    return !(matrix[0][2] == 7 && matrix[2][0] == 3);
}
