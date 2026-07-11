#include <stdio.h>
static int degree_sum(const int edges[][2],int count,int degree[],int n){int i;for(i=0;i<n;++i)degree[i]=0;for(i=0;i<count;++i){++degree[edges[i][0]];++degree[edges[i][1]];}int sum=0;for(i=0;i<n;++i)sum+=degree[i];return sum;}
int main(void){static const int edges[5][2]={{0,1},{0,2},{1,3},{2,3},{3,4}};int degree[5];int sum=degree_sum(edges,5,degree,5);printf("c8922 degrees=%d,%d\n",sum,degree[3]);return !(sum==10&&degree[3]==3);}
