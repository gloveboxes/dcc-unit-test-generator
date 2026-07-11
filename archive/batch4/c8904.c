#include <stdio.h>
static int max_subarray(const int *a,int n){int best=a[0],running=a[0],i;for(i=1;i<n;++i){if(running<0)running=0;running+=a[i];if(running>best)best=running;}return best;}
int main(void){int a[8]={-2,3,-1,5,-6,4,2,-1};printf("c8904 kadane=%d\n",max_subarray(a,8));return 0;}
