#include <stdio.h>
#include <stdbool.h>
static bool is_prime(int n){int d;if(n<2)return false;for(d=2;d*d<=n;++d)if(n%d==0)return false;return true;}
int main(void){int i,count;count=0;for(i=2;i<=31;++i)if(is_prime(i))++count;printf("c9914 boolprime=%d,%d\n",count,is_prime(29));return 0;}
