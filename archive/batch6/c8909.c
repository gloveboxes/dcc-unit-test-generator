#include <stdio.h>
static int checksum(const unsigned char *p,int n){int i,r=0;for(i=0;i<n;++i)r=(r+p[i])%97;return r;}
int main(void){static const unsigned char p[]={4,8,15,16,23,42};printf("c8909 checksum=%d\n",checksum(p,6));return 0;}
