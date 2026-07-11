#include <stdio.h>
#include <stdbool.h>
static int prime_count(int limit){bool composite[64]={false};int count=0;for(int p=2;p*p<=limit;++p)if(!composite[p])for(int n=p*p;n<=limit;n+=p)composite[n]=true;for(int n=2;n<=limit;++n)if(!composite[n])++count;return count;}
int main(void){int count=prime_count(50);printf("c9906 primes=%d\n",count);return count!=15;}
