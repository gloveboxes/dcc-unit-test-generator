#include <stdio.h>
static unsigned checksum(const unsigned char *data,int count){unsigned sum=0;int i;for(i=0;i<count;++i)sum=(sum+data[i])&255;return sum;}
int main(void){static const unsigned char data[]={17,34,51,68,85};printf("c8902 checksum=%u\n",checksum(data,5));return 0;}
