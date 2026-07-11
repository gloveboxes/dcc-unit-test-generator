#include <stdio.h>
#include <stdbool.h>
#define N 5
static bool bipartite(const bool graph[N][N]){int color[N];for(int i=0;i<N;++i)color[i]=-1;for(int start=0;start<N;++start)if(color[start]<0){int queue[N],head=0,tail=0;color[start]=0;queue[tail++]=start;while(head<tail){int node=queue[head++];for(int next=0;next<N;++next)if(graph[node][next]){if(color[next]<0){color[next]=1-color[node];queue[tail++]=next;}else if(color[next]==color[node])return false;}}}return true;}
int main(void){static const bool graph[N][N]={{0,1,0,1,0},{1,0,1,0,0},{0,1,0,1,0},{1,0,1,0,1},{0,0,0,1,0}};bool ok=bipartite(graph);printf("c9918 bipartite=%d\n",(int)ok);return !ok;}
