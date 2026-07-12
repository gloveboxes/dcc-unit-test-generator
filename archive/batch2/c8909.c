#include <stdio.h>
int main(void){int value=360,factor=2,count=0;long encoded=0;while(value>1){while(value%factor==0){encoded=encoded*10+factor;++count;value/=factor;}++factor;}printf("c8909 factors=%ld count=%d\n",encoded,count);return 0;}
