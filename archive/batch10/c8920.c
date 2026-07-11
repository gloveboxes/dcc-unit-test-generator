#include <stdio.h>

static unsigned encode(unsigned nibble)
{
    unsigned d1,d2,d3,d4,p1,p2,p4;
    d1=nibble&1U;d2=(nibble>>1)&1U;d3=(nibble>>2)&1U;d4=(nibble>>3)&1U;
    p1=d1^d2^d4;p2=d1^d3^d4;p4=d2^d3^d4;
    return p1|(p2<<1)|(d1<<2)|(p4<<3)|(d2<<4)|(d3<<5)|(d4<<6);
}
static unsigned correct(unsigned word,int *bit)
{
    unsigned s1,s2,s4,syndrome;
    s1=((word>>0)^(word>>2)^(word>>4)^(word>>6))&1U;s2=((word>>1)^(word>>2)^(word>>5)^(word>>6))&1U;s4=((word>>3)^(word>>4)^(word>>5)^(word>>6))&1U;
    syndrome=s1|(s2<<1)|(s4<<2);*bit=(int)syndrome;if(syndrome)word^=1U<<(syndrome-1);return word;
}

int main(void)
{
    unsigned original,damaged,fixed;int bit;original=encode(11U);damaged=original^(1U<<4);fixed=correct(damaged,&bit);
    printf("c8920 hamming=%02x,%d,%d\n",fixed,bit,fixed==original);
    return !(fixed==original&&bit==5);
}
