#include <stdio.h>
static int max_subarray(const int a[],int n){int best=a[0],cur=a[0],i;for(i=1;i<n;++i){cur=a[i]+(cur>0?cur:0);if(cur>best)best=cur;}return best;}
int main(void){int a[8]={-2,1,-3,4,-1,2,1,-5};int result=max_subarray(a,8);printf("c8906 maxsub=%d\n",result);return result!=6;}
