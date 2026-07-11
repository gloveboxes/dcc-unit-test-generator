#include <stdio.h>
static int border_sum(int rows,int grid[rows][3]){int total=0;for(int r=0;r<rows;++r)for(int c=0;c<3;++c)if(r==0||r==rows-1||c==0||c==2)total+=grid[r][c];return total;}
int main(void){int grid[3][3]={{1,2,3},{4,5,6},{7,8,9}};int sum=border_sum(3,grid);printf("c9911 border=%d\n",sum);return sum!=40;}
