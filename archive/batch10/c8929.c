#include <stdio.h>

struct Thermostat { int active; int low; int high; };
static int update(struct Thermostat *t,int temperature)
{
    if(!t->active&&temperature<=t->low)t->active=1;else if(t->active&&temperature>=t->high)t->active=0;return t->active;
}

int main(void)
{
    struct Thermostat t={0,185,205};int samples[9]={210,200,184,190,204,206,180,205,201};int i,trace;trace=0;
    for(i=0;i<9;++i)trace=trace*2+update(&t,samples[i]);
    printf("c8929 thermostat=%d,%d\n",trace,t.active);
    return !(trace==116&&t.active==0);
}
