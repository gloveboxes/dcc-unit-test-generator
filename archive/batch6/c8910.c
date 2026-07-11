#include <stdio.h>
static int xor_checksum(const unsigned char *p,int n){int i,r=0;for(i=0;i<n;++i)r^=p[i];return r;}
int main(void){static const unsigned char p[]="CPM";printf("c8910 xor=%d\n",xor_checksum(p,3));return 0;}
