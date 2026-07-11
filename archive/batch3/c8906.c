#include <stdio.h>
static void convert(unsigned n,int base,char *out){char digits[]="0123456789ABCDEF";char tmp[16];int i,j;i=0;do{tmp[i++]=digits[n%base];n/=base;}while(n!=0);for(j=0;j<i;++j)out[j]=tmp[i-j-1];out[i]='\0';}
int main(void){char a[16],b[16];convert(493,16,a);convert(493,7,b);printf("c8906 base=%s/%s\n",a,b);return 0;}
