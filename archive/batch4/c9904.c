#include <stdio.h>
static void prefix_sum(int n,const int input[n],int output[n]){int i,total=0;for(i=0;i<n;++i){total+=input[i];output[i]=total;}}
int main(void){int input[5]={3,1,4,1,5},output[5];prefix_sum(5,input,output);printf("c9904 prefix=%d,%d,%d\n",output[1],output[3],output[4]);return 0;}
