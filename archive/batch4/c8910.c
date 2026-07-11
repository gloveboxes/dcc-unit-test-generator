#include <stdio.h>
static int bfs(const int graph[5][5],int start,int target){int queue[5],seen[5]={0,0,0,0,0};int head=0,tail=0,i;queue[tail++]=start;seen[start]=1;while(head<tail){int node=queue[head++];if(node==target)return 1;for(i=0;i<5;++i)if(graph[node][i]&&!seen[i]){seen[i]=1;queue[tail++]=i;}}return 0;}
int main(void){int g[5][5]={{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1},{0,0,0,0,0}};printf("c8910 bfs=%d,%d\n",bfs(g,0,4),bfs(g,4,0));return 0;}
