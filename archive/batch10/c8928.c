#include <stdio.h>

static int smooth(int previous,int sample,int weight)
{
    return (previous*(100-weight)+sample*weight+50)/100;
}

int main(void)
{
    int samples[6]={100,112,108,125,119,121};int value,i,trace;value=samples[0];trace=0;
    for(i=1;i<6;++i){value=smooth(value,samples[i],25);trace=trace*3+(value%10);}
    printf("c8928 smoothing=%d,%d\n",value,trace);
    return !(value==114&&trace==442);
}
