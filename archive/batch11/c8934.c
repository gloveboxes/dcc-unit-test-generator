#include <stdio.h>
static int count_ways_stairs(int n){int a=1,b=1,i;for(i=2;i<=n;++i){int c=a+b;a=b;b=c;}return b;}
int main(void){int a=count_ways_stairs(6),b=count_ways_stairs(10);printf("c8934 stairs=%d,%d\n",a,b);return !(a==13&&b==89);}
