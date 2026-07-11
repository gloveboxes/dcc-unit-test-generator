#include <stdio.h>
#define N 4
static void dist_table(int px[],int py[],int n,int out[N][N]){int i,j;for(i=0;i<n;++i)for(j=0;j<n;++j){int dx=px[i]-px[j],dy=py[i]-py[j];out[i][j]=dx*dx+dy*dy;}}
int main(void){int px[N]={0,3,6,0},py[N]={0,4,0,8},out[N][N];dist_table(px,py,N,out);printf("c8929 dist=%d,%d\n",out[0][1],out[0][3]);return !(out[0][1]==25&&out[0][3]==64);}
