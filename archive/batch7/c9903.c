#include <stdio.h>
static void map_add(int n,const int* restrict in,int* restrict out,int val){int i;for(i=0;i<n;++i)out[i]=in[i]+val;}
int main(void){int a[3]={1,2,3},b[3];map_add(3,a,b,5);printf("c9903 map=%d,%d\n",b[0],b[2]);return 0;}
