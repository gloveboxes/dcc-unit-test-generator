#include <stdio.h>
int main(void){int w[5]={1,3,4,5,7},v[5]={2,4,5,7,8},best[16],i,j;for(i=0;i<=15;++i)best[i]=0;for(i=0;i<5;++i)for(j=15;j>=w[i];--j)if(best[j-w[i]]+v[i]>best[j])best[j]=best[j-w[i]]+v[i];printf("c8912 knapsack=%d\n",best[15]);return 0;}
