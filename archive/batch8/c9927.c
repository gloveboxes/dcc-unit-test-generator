#include <stdio.h>
static inline int saturating_add(int a,int b,int limit){int sum=a+b;return sum>limit?limit:sum;}
int main(void){int a=saturating_add(70,50,100),b=saturating_add(20,30,100);printf("c9927 saturate=%d,%d\n",a,b);return !(a==100&&b==50);}
