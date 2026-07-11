#include <stdio.h>
#define MAXN 20
static long fib(int n,long memo[]){if(n<=1)return n;if(memo[n])return memo[n];memo[n]=fib(n-1,memo)+fib(n-2,memo);return memo[n];}
int main(void){long memo[MAXN+1];int i;for(i=0;i<=MAXN;++i)memo[i]=0;long a=fib(10,memo),b=fib(20,memo);printf("c8904 fib=%ld,%ld\n",a,b);return !(a==55L&&b==6765L);}
