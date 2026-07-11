#include <stdio.h>
#define N 5
static int shortest(const int graph[N][N],int source,int target){int dist[N],used[N],i,j,best,node=-1;for(i=0;i<N;++i){dist[i]=30000;used[i]=0;}dist[source]=0;for(i=0;i<N;++i){best=30000;node=-1;for(j=0;j<N;++j)if(!used[j]&&dist[j]<best){best=dist[j];node=j;}if(node<0)break;used[node]=1;for(j=0;j<N;++j)if(graph[node][j]>0&&dist[node]+graph[node][j]<dist[j])dist[j]=dist[node]+graph[node][j];}return dist[target];}
int main(void){static const int g[N][N]={{0,4,1,0,0},{0,0,2,1,0},{0,1,0,5,0},{0,0,0,0,3},{0,0,0,0,0}};int d=shortest(g,0,4);printf("c8921 path=%d\n",d);return d!=6;}
