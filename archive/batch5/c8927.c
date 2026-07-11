#include <stdio.h>
static int convert(unsigned n,int base,char *out){char d[]="0123456789ABCDEF",t[16];int i=0,j;do{t[i++]=d[n%base];n/=base;}while(n);for(j=0;j<i;++j)out[j]=t[i-j-1];out[i]=0;return i;}
int main(void){char a[16],b[16];convert(493,16,a);convert(493,7,b);printf("c8927 base=%s/%s\n",a,b);return 0;}
