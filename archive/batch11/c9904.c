#include <stdio.h>
#include <stdbool.h>
static bool sudoku_row_ok(const int row[9]) {
    bool seen[10] = {false};
    for (int i = 0; i < 9; i++) {
        if (row[i] < 1 || row[i] > 9 || seen[row[i]]) return false;
        seen[row[i]] = true;
    }
    return true;
}
int main(void) {
    int good[9] = {5,3,4,6,7,8,9,1,2};
    int bad[9]  = {5,3,4,6,7,8,9,1,5};
    bool a = sudoku_row_ok(good), b = sudoku_row_ok(bad);
    printf("c9904 sudoku=%d,%d\n", (int)a, (int)b);
    return !(a && !b);
}
