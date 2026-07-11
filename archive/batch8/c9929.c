#include <stdio.h>
static long dot_product(int count,const int * restrict a,const int * restrict b){long total=0L;for(int i=0;i<count;++i)total+=(long)a[i]*b[i];return total;}
int main(void){int a[4]={1,2,3,4},b[4]={5,6,7,8};long actual=dot_product(4,a,b);printf("c9929 dot=%ld\n",actual);return actual!=70L;}
