#include <stdio.h>
struct Color { union { struct { unsigned char red,green,blue,alpha; }; unsigned char channel[4]; }; };
static int brightness(const struct Color *c){return (c->red+c->green+c->blue)/3;}
int main(void){struct Color c={{.red=30,.green=60,.blue=90,.alpha=255}};int actual=brightness(&c);printf("c1105 color=%d,%u\n",actual,(unsigned)c.channel[3]);return !(actual==60&&c.alpha==255);}
