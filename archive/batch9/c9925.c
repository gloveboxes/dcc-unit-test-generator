#include <stdio.h>
#include <stdbool.h>
#define COUNT 6
static bool acyclic(const bool edges[COUNT][COUNT]){int degree[COUNT]={0},queue[COUNT],head=0,tail=0,visited=0;for(int from=0;from<COUNT;++from)for(int to=0;to<COUNT;++to)if(edges[from][to])++degree[to];for(int i=0;i<COUNT;++i)if(degree[i]==0)queue[tail++]=i;while(head<tail){int node=queue[head++];++visited;for(int to=0;to<COUNT;++to)if(edges[node][to]&&--degree[to]==0)queue[tail++]=to;}return visited==COUNT;}
int main(void){static const bool edges[COUNT][COUNT]={{0,1,1,0,0,0},{0,0,0,1,0,0},{0,0,0,1,1,0},{0,0,0,0,0,1},{0,0,0,0,0,1},{0,0,0,0,0,0}};bool ok=acyclic(edges);printf("c9925 acyclic=%d\n",(int)ok);return !ok;}
