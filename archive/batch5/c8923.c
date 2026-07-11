#include <stdio.h>
static int josephus(int n,int k){int i,r=0;for(i=2;i<=n;++i)r=(r+k)%i;return r+1;}
int main(void){printf("c8923 josephus=%d,%d\n",josephus(7,3),josephus(10,2));return 0;}
