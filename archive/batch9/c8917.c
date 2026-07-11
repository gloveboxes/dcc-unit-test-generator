#include <stdio.h>
static int knapsack(const int weight[],const int value[],int count,int capacity){int best[16];int i,w;for(w=0;w<=capacity;++w)best[w]=0;for(i=0;i<count;++i)for(w=capacity;w>=weight[i];--w)if(best[w-weight[i]]+value[i]>best[w])best[w]=best[w-weight[i]]+value[i];return best[capacity];}
int main(void){int w[4]={2,3,4,5},v[4]={3,4,5,8};int actual=knapsack(w,v,4,8);printf("c8917 sack=%d\n",actual);return actual!=12;}
