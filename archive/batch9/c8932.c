#include <stdio.h>
static unsigned long next_random(unsigned long *state){unsigned long x=*state;x^=(x<<13)&0xFFFFFFFFUL;x^=x>>17;x^=(x<<5)&0xFFFFFFFFUL;x&=0xFFFFFFFFUL;*state=x;return x;}
int main(void){unsigned long state=1UL,a=next_random(&state),b=next_random(&state);printf("c8932 random=%08lx,%08lx\n",a,b);return !(a==0x00042021UL&&b==0x04080601UL);}
