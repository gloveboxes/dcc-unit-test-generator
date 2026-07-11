#include <stdio.h>
static int maxsum(const int *a,int n){int best=a[0],run=a[0],i;for(i=1;i<n;++i){if(run<0)run=0;run+=a[i];if(run>best)best=run;}return best;}
int main(void){int a[7]={-3,4,-1,5,-8,2,3};printf("c8919 maxsum=%d\n",maxsum(a,7));return 0;}
