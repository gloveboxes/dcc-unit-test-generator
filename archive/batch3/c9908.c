#include <stdio.h>
static const int weights[10]={[2]=4,[4]=8,[7]=3};
int main(void){int i,total;total=0;for(i=0;i<10;++i)total+=weights[i]*(i+1);printf("c9908 sparse=%d,%d\n",total,weights[5]);return 0;}
