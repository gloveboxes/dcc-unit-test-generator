#include <stdio.h>
struct TreeItem{int k;union{struct{int l;int r;};int cl[2];};};
int main(void){struct TreeItem t={5,{.l=3,.r=7}};printf("c1124 tree=%d,%d\n",t.cl[0],t.cl[1]);return 0;}
