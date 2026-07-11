#include <stdio.h>
#define NODES 6
static int bfs(const unsigned char graph[NODES][NODES],int start,int goal){int q[NODES],dist[NODES],head=0,tail=0,i,node;for(i=0;i<NODES;++i)dist[i]=-1;dist[start]=0;q[tail++]=start;while(head<tail){node=q[head++];if(node==goal)return dist[node];for(i=0;i<NODES;++i)if(graph[node][i]&&dist[i]<0){dist[i]=dist[node]+1;q[tail++]=i;}}return -1;}
int main(void){static const unsigned char g[NODES][NODES]={{0,1,1,0,0,0},{0,0,0,1,0,0},{0,0,0,1,1,0},{0,0,0,0,0,1},{0,0,0,0,0,1},{0,0,0,0,0,0}};int d=bfs(g,0,5);printf("c8920 bfs=%d\n",d);return d!=3;}
