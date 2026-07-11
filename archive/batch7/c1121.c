#include <stdio.h>
struct BitCount{unsigned b0:1;unsigned b1:1;unsigned b2:1;};
static int pop(struct BitCount b){return b.b0+b.b1+b.b2;}
int main(void){printf("c1121 pop=%d\n",pop((struct BitCount){1,0,1}));return 0;}
