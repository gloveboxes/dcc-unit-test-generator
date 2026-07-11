#include <stdio.h>
#define BITS 32
static int sieve_bits[BITS/16+1];
static void sieve(int limit){int i,j;for(i=0;i<(int)(sizeof(sieve_bits)/sizeof(sieve_bits[0]));++i)sieve_bits[i]=-1;sieve_bits[0]&=~3;for(i=2;(long)i*i<=limit;++i){if(sieve_bits[i/16]&(1<<(i%16)))for(j=i*i;j<=limit;j+=i)sieve_bits[j/16]&=~(1<<(j%16));}}
static int count_primes(int limit){int n=0,i;for(i=2;i<=limit;++i)if(sieve_bits[i/16]&(1<<(i%16)))++n;return n;}
int main(void){sieve(30);int n=count_primes(30);printf("c8923 sieve=%d\n",n);return n!=10;}
