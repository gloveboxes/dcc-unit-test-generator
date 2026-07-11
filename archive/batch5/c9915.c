#include <stdio.h>
static int encode(int n,char *out){char d[]="0123456789ABCDEF",t[8];int i=0,j;do{t[i++]=d[n%16];n/=16;}while(n);for(j=0;j<i;++j)out[j]=t[i-j-1];out[i]=0;return i;}
int main(void){char s[8];printf("c9915 hex=%d/%s\n",encode(48879,s),s);return 0;}
