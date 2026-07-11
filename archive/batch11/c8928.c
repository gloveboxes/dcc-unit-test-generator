#include <stdio.h>
static int factor_display(int n,int primes[],int exps[],int cap){int used=0,d;for(d=2;(long)d*d<=n;++d){if(n%d==0){if(used<cap){primes[used]=d;exps[used]=0;}while(n%d==0){if(used<cap)++exps[used];n/=d;}++used;}}if(n>1&&used<cap){primes[used]=n;exps[used]=1;++used;}return used;}
int main(void){int primes[8],exps[8];int k=factor_display(360,primes,exps,8);printf("c8928 factors=%d,%d^%d,%d^%d,%d^%d\n",k,primes[0],exps[0],primes[1],exps[1],primes[2],exps[2]);return !(k==3&&primes[0]==2&&exps[0]==3&&primes[1]==3&&primes[2]==5);}
