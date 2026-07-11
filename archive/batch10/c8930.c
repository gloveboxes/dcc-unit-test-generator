#include <stdio.h>

static int choose(int floor,int direction,unsigned requests)
{
    int d,next;if(direction>0){for(d=floor+1;d<8;++d)if(requests&(1U<<d))return d;}else{for(d=floor-1;d>=0;--d)if(requests&(1U<<d))return d;}
    next=-1;for(d=0;d<8;++d)if(requests&(1U<<d))if(next<0||((d-floor<0?floor-d:d-floor)<(next-floor<0?floor-next:next-floor)))next=d;return next;
}

int main(void)
{
    int a,b,c;a=choose(3,1,(1U<<1)|(1U<<5)|(1U<<7));b=choose(6,-1,(1U<<2)|(1U<<4)|(1U<<7));c=choose(4,1,(1U<<1)|(1U<<2));
    printf("c8930 elevator=%d,%d,%d\n",a,b,c);
    return !(a==5&&b==4&&c==2);
}
