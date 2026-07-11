#include <stdio.h>
static int window_sum(int n,int width,const int values[n]){int i,total;total=0;for(i=0;i<width;++i)total+=values[i];return total;}
int main(void){int values[5]={4,7,1,9,2};printf("c9911 window=%d\n",window_sum(5,3,values));return 0;}
