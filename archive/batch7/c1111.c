#include <stdio.h>
struct ColorBits{unsigned r:5;unsigned g:6;unsigned b:5;};
static unsigned to_int(struct ColorBits c){return c.r|(c.g<<5)|(c.b<<11);}
int main(void){printf("c1111 col=%x\n",to_int((struct ColorBits){31,0,0}));return 0;}
