#include <stdio.h>
static int root(int parent[],int node){while(parent[node]!=node){parent[node]=parent[parent[node]];node=parent[node];}return node;}
static void unite(int parent[],int a,int b){int ra=root(parent,a),rb=root(parent,b);if(ra!=rb)parent[rb]=ra;}
int main(void){int parent[6],i,a,b;for(i=0;i<6;++i)parent[i]=i;unite(parent,0,1);unite(parent,1,2);unite(parent,4,5);a=root(parent,0)==root(parent,2);b=root(parent,0)==root(parent,5);printf("c8922 union=%d,%d\n",a,b);return !(a&&!b);}
