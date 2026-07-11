#include <stdio.h>

int main(void)
{
    int board[5][5] = {{0,1,0,0,0},{0,0,1,0,0},{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int next[5][5], r, c, dr, dc, neighbors, alive = 0;
    for (r = 0; r < 5; ++r) for (c = 0; c < 5; ++c) {
        neighbors = 0;
        for (dr = -1; dr <= 1; ++dr) for (dc = -1; dc <= 1; ++dc)
            if ((dr || dc) && r + dr >= 0 && r + dr < 5 && c + dc >= 0 && c + dc < 5)
                neighbors += board[r + dr][c + dc];
        next[r][c] = neighbors == 3 || (board[r][c] && neighbors == 2);
        alive += next[r][c];
    }
    printf("c8913 alive=%d\n", alive);
    return 0;
}
