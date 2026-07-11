#include <stdio.h>
int main(void){int values[7]={1,2,3,4,5,6,7},i,left=0,right=6,temp;for(i=0;i<3;++i){temp=values[left+i];values[left+i]=values[right-i];values[right-i]=temp;}printf("c9916 reverse=%d%d%d%d%d%d%d\n",values[0],values[1],values[2],values[3],values[4],values[5],values[6]);return 0;}
