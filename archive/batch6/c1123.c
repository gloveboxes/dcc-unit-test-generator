#include <stdio.h>
struct Counter{unsigned value:7;unsigned wrapped:1;};
static struct Counter increment(struct Counter c){if(c.value==127){c.value=0;c.wrapped=1;}else ++c.value;return c;}
int main(void){struct Counter a={126,0},b={127,0};a=increment(a);b=increment(b);printf("c1123 counter=%u,%u,%u\n",a.value,b.value,b.wrapped);return 0;}
