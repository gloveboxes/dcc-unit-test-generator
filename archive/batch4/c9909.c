#include <stdio.h>
static int count_bytes(int n,const unsigned char data[n],unsigned char target){int i,count=0;for(i=0;i<n;++i)if(data[i]==target)++count;return count;}
int main(void){unsigned char data[7]={2,4,2,8,2,6,2};printf("c9909 vla=%d\n",count_bytes(7,data,2));return 0;}
