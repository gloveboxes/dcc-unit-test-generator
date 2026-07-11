#include <stdio.h>
struct Data{int len;int vals[3];};
static int data_sum(struct Data d){int i,r=0;for(i=0;i<d.len;++i)r+=d.vals[i];return r;}
int main(void){struct Data d={.len=2,.vals={[0]=10,[1]=20}};printf("c9931 dsum=%d\n",data_sum(d));return 0;}
