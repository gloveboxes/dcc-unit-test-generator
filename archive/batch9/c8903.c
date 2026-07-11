#include <stdio.h>
static int select_k(int values[],int count,int k){int i,j,best,t;for(i=0;i<=k;++i){best=i;for(j=i+1;j<count;++j)if(values[j]<values[best])best=j;t=values[i];values[i]=values[best];values[best]=t;}return values[k];}
int main(void){int values[7]={9,2,7,4,1,8,3};int actual=select_k(values,7,3);printf("c8903 select=%d\n",actual);return actual!=4;}
