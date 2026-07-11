#include <stdio.h>
#define N 6
static void counting_sort(const int a[],int n,int out[]){int count[N]={0};int i;for(i=0;i<n;++i)if(a[i]>=0&&a[i]<N)++count[a[i]];int pos[N]={0};for(i=1;i<N;++i)pos[i]=pos[i-1]+count[i-1];int tmp[8];for(i=n-1;i>=0;--i)tmp[pos[a[i]]++]=a[i];for(i=0;i<n;++i)out[i]=tmp[i];}
int main(void){int a[8]={3,1,4,1,5,2,3,2},out[8];counting_sort(a,8,out);printf("c8910 sort=%d%d%d%d%d%d%d%d\n",out[0],out[1],out[2],out[3],out[4],out[5],out[6],out[7]);return !(out[0]==1&&out[7]==5);}
