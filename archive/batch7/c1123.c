#include <stdio.h>
struct Display{unsigned on:1;unsigned cur:1;unsigned blink:1;unsigned:5;};
static int is_on(struct Display d){return d.on;}
int main(void){struct Display d={1,1,0};printf("c1123 disp=%d\n",is_on(d));return 0;}
