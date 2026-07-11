#include <stdio.h>

enum Light { NS_GREEN,NS_YELLOW,ALL_RED,EW_GREEN,EW_YELLOW };
struct Signal { enum Light state; int elapsed; };
static enum Light step(struct Signal *s,int demand)
{
    ++s->elapsed;switch(s->state){case NS_GREEN:if(demand&&s->elapsed>=3){s->state=NS_YELLOW;s->elapsed=0;}break;case NS_YELLOW:if(s->elapsed>=2){s->state=ALL_RED;s->elapsed=0;}break;case ALL_RED:if(s->elapsed>=1){s->state=EW_GREEN;s->elapsed=0;}break;case EW_GREEN:if(s->elapsed>=3){s->state=EW_YELLOW;s->elapsed=0;}break;case EW_YELLOW:if(s->elapsed>=2){s->state=NS_GREEN;s->elapsed=0;}break;}return s->state;
}

int main(void)
{
    struct Signal s={NS_GREEN,0};int demand[11]={0,1,1,1,1,1,1,1,1,1,1};int i;long trace;trace=0L;for(i=0;i<11;++i)trace=trace*5L+step(&s,demand[i]);
    printf("c8931 signals=%ld,%d\n",trace,(int)s.state);
    return !(trace==511745L&&s.state==NS_GREEN);
}
