#include <stdbool.h>
#include <stdio.h>
static bool even(int value){return value%2==0;}
int main(void){int values[6]={2,7,4,9,6,1},i,count=0;for(i=0;i<6;++i)if(even(values[i]))++count;printf("c9904 bool=%d\n",count);return 0;}
