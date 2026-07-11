#include <stdio.h>
static unsigned adler(const unsigned char *p,int n){unsigned a=1,b=0;int i;for(i=0;i<n;++i){a=(a+p[i])%251;b=(b+a)%251;}return b*256+a;}
int main(void){static const unsigned char p[]="abc";printf("c8911 adler=%u\n",adler(p,3));return 0;}
