#include <stdio.h>

static long tax(long income)
{
    long due;if(income<=12000L)return 0L;due=0L;income-=12000L;
    if(income>10000L){due+=1000L;income-=10000L;}else{return income*10L/100L;}
    if(income>20000L){due+=3000L;income-=20000L;}else{return due+income*15L/100L;}
    return due+income*22L/100L;
}

int main(void)
{
    long a,b,c;a=tax(17500L);b=tax(35000L);c=tax(50000L);
    printf("c8926 tax=%ld,%ld,%ld\n",a,b,c);
    return !(a==550L&&b==2950L&&c==5760L);
}
