#include <stdio.h>
#include <stdbool.h>
static int count_islands(int rows, int grid[rows][6], int cols) {
    bool visited[rows][6];
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++) visited[r][c] = false;
    int islands = 0;
    int stack[64][2]; int top;
    for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++) {
        if (grid[r][c] && !visited[r][c]) {
            islands++; top = 0;
            stack[top][0]=r; stack[top++][1]=c;
            while (top) {
                int cr=stack[--top][0], cc=stack[top][1];
                if (cr<0||cr>=rows||cc<0||cc>=cols||!grid[cr][cc]||visited[cr][cc]) continue;
                visited[cr][cc]=true;
                if (top+4<64) {
                    stack[top][0]=cr-1;stack[top++][1]=cc;
                    stack[top][0]=cr+1;stack[top++][1]=cc;
                    stack[top][0]=cr;stack[top++][1]=cc-1;
                    stack[top][0]=cr;stack[top++][1]=cc+1;
                }
            }
        }
    }
    return islands;
}
int main(void) {
    int g[4][6] = {{1,1,0,0,0,1},{1,0,0,1,1,0},{0,0,0,1,0,0},{0,1,0,0,0,0}};
    int n = count_islands(4, g, 6);
    printf("c9906 islands=%d\n", n);
    return n != 4;
}
