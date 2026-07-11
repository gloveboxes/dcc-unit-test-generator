#include <stdio.h>

struct Controller { union { struct { int proportional,integral,derivative; };int gain[3]; };int accumulated,previous; };
static int update(struct Controller *c,int error){int change=error-c->previous;c->accumulated+=error;c->previous=error;return c->proportional*error+c->integral*c->accumulated+c->derivative*change;}
int main(void){struct Controller c={.proportional=2,.integral=1,.derivative=3,.accumulated=0,.previous=0};int a=update(&c,5),b=update(&c,3);printf("c1126 controller=%d,%d,%d\n",a,b,c.gain[2]);return !(a==30&&b==8&&c.gain[2]==3);}
