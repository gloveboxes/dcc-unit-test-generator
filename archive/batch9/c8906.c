#include <stdio.h>
static unsigned long adler32(const unsigned char *data,int count){unsigned long a=1UL,b=0UL;int i;for(i=0;i<count;++i){a=(a+data[i])%65521UL;b=(b+a)%65521UL;}return (b<<16)|a;}
int main(void){static const unsigned char data[]="CPM22";unsigned long actual=adler32(data,5);printf("c8906 adler=%08lx\n",actual);return actual!=0x04110145UL;}
