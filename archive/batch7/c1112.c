#include <stdio.h>
struct NodeData{union{struct{int a;int b;};int x[2];};};
int main(void){struct NodeData nd={{.a=5,.b=6}};printf("c1112 ndata=%d,%d\n",nd.x[0],nd.x[1]);return 0;}
