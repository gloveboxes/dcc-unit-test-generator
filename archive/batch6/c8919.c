#include <stdio.h>
static int combinations(int n,int k){int i,r=1;for(i=1;i<=k;++i)r=r*(n-k+i)/i;return r;}
int main(void){printf("c8919 choose=%d,%d\n",combinations(6,2),combinations(8,3));return 0;}
