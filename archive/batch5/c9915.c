#include <stdio.h>
#include <stdint.h>
static int encode(uint16_t n,char *out){char d[]="0123456789ABCDEF",t[8];int i=0,j;do{t[i++]=d[n%16];n/=16;}while(n);for(j=0;j<i;++j)out[j]=t[i-j-1];out[i]=0;return i;}
int main(void){char s[8];int count=encode(48879,s);printf("c9915 hex=%d/%s\n",count,s);return 0;}
