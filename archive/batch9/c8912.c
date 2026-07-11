#include <stdio.h>
static int format_base(unsigned value,unsigned base,char out[],int cap){static const char digits[]="0123456789ABCDEF";char rev[17];int n=0,i;if(base<2||base>16)return 0;do{rev[n++]=digits[value%base];value/=base;}while(value&&n<17);if(n+1>cap)return 0;for(i=0;i<n;++i)out[i]=rev[n-1-i];out[n]='\0';return n;}
int main(void){char out[8];int n=format_base(48879U,16U,out,8);printf("c8912 base=%d,%s\n",n,out);return !(n==4&&out[0]=='B'&&out[3]=='F');}
