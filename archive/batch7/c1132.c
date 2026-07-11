#include <stdio.h>
struct ColorBits8{unsigned r:3;unsigned g:3;unsigned b:2;};
static unsigned to_b(struct ColorBits8 c){return c.b;}
int main(void){printf("c1132 c8=%u\n",to_b((struct ColorBits8){7,7,3}));return 0;}
