#include <stdio.h>
static unsigned int reverse_bits16(unsigned int v){unsigned int r=0;int i;for(i=0;i<16;++i){r=(r<<1)|(v&1U);v>>=1;}return r;}
int main(void){unsigned int a=reverse_bits16(0xA0C0U),b=reverse_bits16(a);printf("c8913 revbits=%04x,%04x\n",a,b);return !(a==0x0305U&&b==0xA0C0U);}
