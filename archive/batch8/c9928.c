#include <stdio.h>
static int unique_sorted(int count,int values[count]){int out=0;for(int i=0;i<count;++i)if(i==0||values[i]!=values[i-1])values[out++]=values[i];return out;}
int main(void){int values[7]={1,1,2,2,2,5,8};int count=unique_sorted(7,values);printf("c9928 unique=%d,%d\n",count,values[3]);return !(count==4&&values[3]==8);}
