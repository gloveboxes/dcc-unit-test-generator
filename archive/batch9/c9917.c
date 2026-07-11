#include <stdio.h>
static int unique_count(int count,const int input[count]){int unique[count];int used=0;for(int i=0;i<count;++i){int seen=0;for(int j=0;j<used;++j)if(unique[j]==input[i])seen=1;if(!seen)unique[used++]=input[i];}return used;}
int main(void){int values[8]={3,1,3,2,1,4,2,5};int count=unique_count(8,values);printf("c9917 unique=%d\n",count);return count!=5;}
