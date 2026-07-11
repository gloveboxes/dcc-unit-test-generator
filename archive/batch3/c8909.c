#include <stdio.h>
int main(void){int prime[51],i,j,count;for(i=0;i<=50;++i)prime[i]=1;prime[0]=prime[1]=0;for(i=2;i<=7;++i)if(prime[i])for(j=i*i;j<=50;j+=i)prime[j]=0;count=0;for(i=2;i<=50;++i)if(prime[i])++count;printf("c8909 primes=%d,%d\n",count,prime[47]);return 0;}
