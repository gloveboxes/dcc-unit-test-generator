#include <stdio.h>

struct Bucket { int tokens; int capacity; int refill; };
static int request(struct Bucket *b,int ticks,int cost)
{
    b->tokens+=ticks*b->refill;if(b->tokens>b->capacity)b->tokens=b->capacity;if(cost>b->tokens)return 0;b->tokens-=cost;return 1;
}

int main(void)
{
    struct Bucket b={3,10,2};int ok[5],accepted,i,trace;ok[0]=request(&b,1,4);ok[1]=request(&b,0,3);ok[2]=request(&b,2,5);ok[3]=request(&b,1,4);ok[4]=request(&b,3,7);accepted=0;trace=0;for(i=0;i<5;++i){accepted+=ok[i];trace=trace*2+ok[i];}
    printf("c8932 bucket=%d,%d,%d\n",accepted,trace,b.tokens);
    return !(accepted==3&&trace==21&&b.tokens==1);
}
