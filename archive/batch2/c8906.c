#include <stdio.h>
int main(void){int graph[5][5]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,1},{0,1,1,0,1},{0,0,1,1,0}},seen[5]={0},queue[5],head=0,tail=0,order=0,v,i;queue[tail++]=0;seen[0]=1;while(head<tail){v=queue[head++];order=order*10+v;for(i=0;i<5;++i)if(graph[v][i]&&!seen[i]){seen[i]=1;queue[tail++]=i;}}printf("c8906 bfs=%d\n",order);return 0;}
