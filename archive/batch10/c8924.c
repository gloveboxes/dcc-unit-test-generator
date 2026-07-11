#include <stdio.h>

static unsigned segments(int digit)
{
    static const unsigned char map[10]={0x3FU,0x06U,0x5BU,0x4FU,0x66U,0x6DU,0x7DU,0x07U,0x7FU,0x6FU};
    return map[digit];
}
static int count_bits(unsigned value){int n;n=0;while(value){n+=(int)(value&1U);value>>=1;}return n;}

int main(void)
{
    int digits[4]={2,0,2,6};int i,lit;unsigned signature;lit=0;signature=0;
    for(i=0;i<4;++i){lit+=count_bits(segments(digits[i]));signature=(signature<<2)^(segments(digits[i])&3U);}
    printf("c8924 display=%d,%u\n",lit,signature);
    return !(lit==22&&signature==253U);
}
