#include <stdio.h>
struct Color{int r;int g;int b;};
static struct Color mix(struct Color c1,struct Color c2){return (struct Color){(c1.r+c2.r)/2,(c1.g+c2.g)/2,(c1.b+c2.b)/2};}
int main(void){struct Color c=mix((struct Color){10,20,30},(struct Color){30,40,50});printf("c9913 mix=%d,%d,%d\n",c.r,c.g,c.b);return 0;}
