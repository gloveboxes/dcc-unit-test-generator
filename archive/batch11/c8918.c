#include <stdio.h>
static int zeckendorf(int n,int terms[],int cap){int fib[16],k=2,i;fib[0]=1;fib[1]=2;while(fib[k-1]+fib[k-2]<=n){fib[k]=fib[k-1]+fib[k-2];++k;}int used=0;for(i=k-1;i>=0&&n>0;--i){if(fib[i]<=n){if(used<cap)terms[used]=fib[i];++used;n-=fib[i];}}return used;}
int main(void){int terms[8];int count=zeckendorf(100,terms,8);printf("c8918 zeck=%d,%d,%d\n",count,terms[0],terms[count-1]);return !(count==3&&terms[0]==89&&terms[2]==3);}
