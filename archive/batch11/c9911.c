#include <stdio.h>
#include <stdbool.h>
static bool nqueens(int n, int cols[], int row) {
    if (row == n) return true;
    for (int c = 0; c < n; c++) {
        bool ok = true;
        for (int r = 0; r < row; r++)
            if (cols[r] == c || cols[r] - c == r - row || cols[r] - c == row - r)
                { ok = false; break; }
        if (ok) { cols[row] = c; if (nqueens(n, cols, row + 1)) return true; }
    }
    return false;
}
int main(void) {
    int cols[8];
    bool ok = nqueens(8, cols, 0);
    printf("c9911 queens=%d,%d\n", (int)ok, cols[0]);
    return !ok;
}
