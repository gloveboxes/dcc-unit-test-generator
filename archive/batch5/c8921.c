#include <stdio.h>
static int sieve(int limit){int p[32],i,j,r=0;for(i=0;i<=limit;++i)p[i]=1;p[0]=p[1]=0;for(i=2;i*i<=limit;++i)if(p[i])for(j=i*i;j<=limit;j+=i)p[j]=0;for(i=2;i<=limit;++i)if(p[i])++r;return r;}
int main(void){printf("c8921 primes=%d,%d\n",sieve(10),sieve(30));return 0;}
