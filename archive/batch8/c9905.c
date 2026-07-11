#include <stdio.h>
#define COLUMNS 3
static int row_max(int rows, const int matrix[rows][COLUMNS], int row) {
    int best = matrix[row][0]; for (int col = 1; col < COLUMNS; ++col) if (matrix[row][col] > best) best = matrix[row][col]; return best;
}
int main(void) {
    int matrix[2][COLUMNS] = {{3,8,1},{7,2,9}}; int actual = row_max(2, matrix, 1);
    printf("c9905 rowmax=%d\n", actual); return actual != 9;
}
