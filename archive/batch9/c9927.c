#include <stdio.h>
static int factor_count(int value){int count=0;for(int divisor=2;divisor*divisor<=value;++divisor)while(value%divisor==0){++count;value/=divisor;}if(value>1)++count;return count;}
int main(void){int a=factor_count(360),b=factor_count(97);printf("c9927 factors=%d,%d\n",a,b);return !(a==6&&b==1);}
