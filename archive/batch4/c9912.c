#include <stdio.h>
static int histogram(int n,const int values[n],int bins[4]){int i,total=0;for(i=0;i<4;++i)bins[i]=0;for(i=0;i<n;++i)if(values[i]>=0&&values[i]<4)++bins[values[i]];for(i=0;i<4;++i)total+=bins[i];return total;}
int main(void){int values[7]={0,3,1,3,2,3,4},bins[4],total;total=histogram(7,values,bins);printf("c9912 histogram=%d,%d\n",total,bins[3]);return 0;}
