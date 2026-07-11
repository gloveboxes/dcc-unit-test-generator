#include <stdio.h>
static int fib(int n){int a=0,b=1,t,i;for(i=0;i<n;++i){t=a+b;a=b;b=t;}return a;}
int main(void){printf("c8904 fib=%d,%d\n",fib(10),fib(15));return 0;}
