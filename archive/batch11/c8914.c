#include <stdio.h>
static long modpow(long base,long exp,long mod){long result=1L;base%=mod;while(exp>0){if(exp&1L)result=result*base%mod;base=base*base%mod;exp>>=1;}return result;}
int main(void){long a=modpow(2L,10L,1000L),b=modpow(3L,13L,97L);printf("c8914 modpow=%ld,%ld\n",a,b);return !(a==24L&&b==31L);}
