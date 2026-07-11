#include <stdio.h>
static int peak(const int *values,int n){int bins[8]={0};int i,max;for(i=0;i<n;++i)++bins[values[i]];max=0;for(i=1;i<8;++i)if(bins[i]>bins[max])max=i;return max;}
int main(void){int samples[9]={2,3,2,5,3,2,7,3,2};printf("c9904 histogram=%d\n",peak(samples,9));return 0;}
