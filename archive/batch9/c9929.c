#include <stdio.h>
#include <stdint.h>
struct Color { uint8_t r,g,b; };
static struct Color blend(const struct Color *a,const struct Color *b){struct Color out={.r=(uint8_t)(((unsigned)a->r+b->r)/2U),.g=(uint8_t)(((unsigned)a->g+b->g)/2U),.b=(uint8_t)(((unsigned)a->b+b->b)/2U)};return out;}
int main(void){struct Color out=blend(&(struct Color){.r=20,.g=40,.b=80},&(struct Color){.r=100,.g=20,.b=40});printf("c9929 blend=%u,%u,%u\n",(unsigned)out.r,(unsigned)out.g,(unsigned)out.b);return !(out.r==60&&out.g==30&&out.b==60);}
