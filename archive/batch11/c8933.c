#include <stdio.h>
static int max_profit(const int prices[],int n){int min=prices[0],best=0,i;for(i=1;i<n;++i){int profit=prices[i]-min;if(profit>best)best=profit;if(prices[i]<min)min=prices[i];}return best;}
int main(void){int prices[7]={7,1,5,3,6,4,8};int profit=max_profit(prices,7);printf("c8933 profit=%d\n",profit);return profit!=7;}
