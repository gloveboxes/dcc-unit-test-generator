#include <stdio.h>
static int range_sum(int count,const int values[count],int begin,int end){int prefix[count+1];prefix[0]=0;for(int i=0;i<count;++i)prefix[i+1]=prefix[i]+values[i];return prefix[end]-prefix[begin];}
int main(void){int values[7]={4,2,7,1,3,6,5};int sum=range_sum(7,values,2,6);printf("c9923 range=%d\n",sum);return sum!=17;}
