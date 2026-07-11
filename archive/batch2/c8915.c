#include <stdio.h>
int main(void){int a[8]={4,1,4,2,4,3,1,4},i,counts[5]={0},mode=0;for(i=0;i<8;++i)++counts[a[i]];for(i=1;i<5;++i)if(counts[i]>counts[mode])mode=i;printf("c8915 mode=%d frequency=%d\n",mode,counts[mode]);return 0;}
