#include <stdio.h>
int main(void){int coins[3]={1,3,4},best[16],i,j,value;best[0]=0;for(value=1;value<=15;++value){best[value]=30000;for(j=0;j<3;++j)if(coins[j]<=value&&best[value-coins[j]]+1<best[value])best[value]=best[value-coins[j]]+1;}i=15;printf("c8905 coins=%d\n",best[i]);return 0;}
