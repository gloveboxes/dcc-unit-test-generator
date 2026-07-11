#include <stdio.h>
static inline int absval(int value){return value<0?-value:value;}
int main(void){int values[5]={-4,3,-9,2,-1},i,total=0;for(i=0;i<5;++i)total+=absval(values[i]);printf("c9908 inline=%d\n",total);return 0;}
