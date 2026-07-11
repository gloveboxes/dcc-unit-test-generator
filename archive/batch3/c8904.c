#include <stdio.h>
static int survivor(int n,int step){int i,pos;pos=0;for(i=2;i<=n;++i)pos=(pos+step)%i;return pos+1;}
int main(void){printf("c8904 josephus=%d,%d\n",survivor(7,3),survivor(10,2));return 0;}
