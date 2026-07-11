#include <stdio.h>
#include <stdbool.h>

static bool region(const int grid[9][9],int top,int left){bool seen[10]={false};for(int r=top;r<top+3;++r)for(int c=left;c<left+3;++c){int v=grid[r][c];if(v<1||v>9||seen[v])return false;seen[v]=true;}return true;}
int main(void){int g[9][9]={{5,3,4},{6,7,2},{1,9,8}};bool a=region(g,0,0);g[2][2]=5;bool b=region(g,0,0);printf("c9914 sudoku=%d,%d\n",(int)a,(int)b);return !(a&&!b);}
