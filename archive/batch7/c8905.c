#include <stdio.h>
static int fib(int n){int a=0,b=1,t,i;if(n<=0)return 0;for(i=2;i<=n;++i){t=a+b;a=b;b=t;}return b;}
int main(void){printf("c8905 fib=%d,%d\n",fib(7),fib(12));return 0;}
