#include <stdio.h>
struct Controller{int integral;int previous;};
static int step(struct Controller *c,int target,int measured){int error=target-measured;int output=2*error+c->integral+(error-c->previous);c->integral+=error;c->previous=error;return output;}
int main(void){struct Controller c={0,0};int a=step(&c,100,90),b=step(&c,100,94);printf("c8927 control=%d,%d\n",a,b);return !(a==30&&b==18);}
