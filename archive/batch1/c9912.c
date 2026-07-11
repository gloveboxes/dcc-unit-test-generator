#include <stdio.h>

int main(void)
{
    int rows = 2, cols = 3, matrix[rows][3], i, j, total = 0;
    for (i = 0; i < rows; ++i) for (j = 0; j < cols; ++j) matrix[i][j] = (i + 1) * (j + 2);
    for (i = 0; i < rows; ++i) for (j = 0; j < cols; ++j) total += matrix[i][j];
    printf("c9912 matrix=%d\n", total);
    return 0;
}
