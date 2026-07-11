#include <stdio.h>
static int find_run(int n,const int values[n],int target){int i,length=0;for(i=0;i<n;++i){if(values[i]==target)++length;else if(length)return length;}return length;}
int main(void){int values[8]={1,1,3,3,3,2,3,3};printf("c9917 run=%d\n",find_run(8,values,3));return 0;}
