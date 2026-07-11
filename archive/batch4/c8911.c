#include <stdio.h>
static int weighted(const int *weights,const int *values,int n,int capacity){int best[12]={0};int i,c;for(i=0;i<n;++i)for(c=capacity;c>=weights[i];--c)if(best[c-weights[i]]+values[i]>best[c])best[c]=best[c-weights[i]]+values[i];return best[capacity];}
int main(void){int w[4]={2,3,4,5},v[4]={3,4,5,8};printf("c8911 knapsack=%d\n",weighted(w,v,4,8));return 0;}
