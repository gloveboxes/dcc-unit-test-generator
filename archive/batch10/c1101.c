#include <stdio.h>
#include <stdint.h>

struct Actuator { int id; union { struct { int16_t minimum,maximum; }; struct { int16_t low,high; }; }; };
static int scale(const struct Actuator *a,int raw){return a->minimum+(long)raw*(a->maximum-a->minimum)/255;}
int main(void){struct Actuator a={.id=3,.minimum=-100,.maximum=300};int x=scale(&a,64),y=scale(&a,255);printf("c1101 actuator=%d,%d,%d\n",x,y,a.low);return !(x==0&&y==300&&a.low==-100);}
