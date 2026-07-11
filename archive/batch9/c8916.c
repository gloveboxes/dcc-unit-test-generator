#include <stdio.h>
static int coin_ways(const int coins[],int count,int amount){int ways[21];int i,j;for(i=0;i<=amount;++i)ways[i]=0;ways[0]=1;for(i=0;i<count;++i)for(j=coins[i];j<=amount;++j)ways[j]+=ways[j-coins[i]];return ways[amount];}
int main(void){int coins[3]={1,2,5};int actual=coin_ways(coins,3,10);printf("c8916 coins=%d\n",actual);return actual!=10;}
