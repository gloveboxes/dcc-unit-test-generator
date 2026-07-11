#include <stdio.h>
#define N 4
static int maze[N][N]={{1,0,0,0},{1,1,0,1},{0,1,0,0},{0,1,1,1}};
static int solve(int r,int c,int visited[N][N]){if(r==N-1&&c==N-1)return 1;if(r<0||r>=N||c<0||c>=N||!maze[r][c]||visited[r][c])return 0;visited[r][c]=1;if(solve(r+1,c,visited)||solve(r,c+1,visited))return 1;visited[r][c]=0;return 0;}
int main(void){int visited[N][N]={{0}};int ok=solve(0,0,visited);printf("c8907 maze=%d\n",ok);return !ok;}
