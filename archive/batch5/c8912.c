#include <stdio.h>
static unsigned crc(const unsigned char *p,int n){unsigned r=0;int i,j;for(i=0;i<n;++i){r^=p[i];for(j=0;j<8;++j)r=(r&1)?(r>>1)^40961:r>>1;}return r;}
int main(void){static const unsigned char p[]="123456789";printf("c8912 crc=%u\n",crc(p,9));return 0;}
