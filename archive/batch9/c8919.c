#include <stdio.h>
#define ROWS 4
#define COLS 5
static int fill(char grid[ROWS][COLS],int row,int col,char from,char to){int stack[ROWS*COLS][2];int top=0,count=0,r,c;if(grid[row][col]!=from)return 0;stack[top][0]=row;stack[top++][1]=col;while(top){--top;r=stack[top][0];c=stack[top][1];if(r<0||r>=ROWS||c<0||c>=COLS||grid[r][c]!=from)continue;grid[r][c]=to;++count;if(top+4<=ROWS*COLS){stack[top][0]=r-1;stack[top++][1]=c;stack[top][0]=r+1;stack[top++][1]=c;stack[top][0]=r;stack[top++][1]=c-1;stack[top][0]=r;stack[top++][1]=c+1;}}return count;}
int main(void){char g[ROWS][COLS]={{1,1,0,0,0},{1,0,0,1,1},{1,1,0,1,0},{0,0,0,1,1}};int n=fill(g,0,0,1,2);printf("c8919 fill=%d\n",n);return n!=5;}
