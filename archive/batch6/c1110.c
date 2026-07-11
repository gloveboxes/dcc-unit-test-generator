#include <stdio.h>
struct Color{unsigned red:5;unsigned green:6;unsigned blue:5;};
static unsigned brightness(struct Color c){return c.red+c.green+c.blue;}
int main(void){struct Color c={10,20,15};printf("c1110 color=%u\n",brightness(c));return 0;}
