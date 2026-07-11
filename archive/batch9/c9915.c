#include <stdio.h>
static void moving_sum(int count,const int *restrict input,int *restrict output){for(int i=1;i<count-1;++i)output[i-1]=input[i-1]+input[i]+input[i+1];}
int main(void){int input[6]={2,4,6,8,10,12},out[4];moving_sum(6,input,out);printf("c9915 window=%d,%d\n",out[0],out[3]);return !(out[0]==12&&out[3]==30);}
