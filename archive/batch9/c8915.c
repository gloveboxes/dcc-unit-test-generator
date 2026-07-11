#include <stdio.h>
static void pascal_row(int row,int values[],int cap){int i;if(row+1>cap)return;values[0]=1;for(i=1;i<=row;++i)values[i]=values[i-1]*(row-i+1)/i;}
int main(void){int values[7];pascal_row(6,values,7);printf("c8915 pascal=%d,%d,%d\n",values[0],values[3],values[6]);return !(values[0]==1&&values[3]==20&&values[6]==1);}
