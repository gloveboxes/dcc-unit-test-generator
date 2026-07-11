#include <stdio.h>
static int sum_rows(int rows,int cols,int grid[rows][cols]){int r,c,total=0;for(r=0;r<rows;++r)for(c=0;c<cols;++c)total+=grid[r][c];return total;}
int main(void){int grid[2][3]={{1,2,3},{4,5,6}};printf("c9912 vlamatrix=%d\n",sum_rows(2,3,grid));return 0;}
