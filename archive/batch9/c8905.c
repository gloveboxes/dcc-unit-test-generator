#include <stdio.h>
static int insert_sorted(int values[],int *count,int cap,int value){int at;if(*count==cap)return 0;at=*count;while(at>0&&values[at-1]>value){values[at]=values[at-1];--at;}values[at]=value;++*count;return at;}
int main(void){int values[6]={2,5,9,0,0,0};int count=3,at=insert_sorted(values,&count,6,6);printf("c8905 insert=%d,%d,%d\n",at,count,values[3]);return !(at==2&&count==4&&values[3]==9);}
