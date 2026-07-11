#include <stdio.h>
static unsigned int gray(unsigned int n){return n^(n>>1);}
static unsigned int gray_inv(unsigned int g){unsigned int n=g;while(g>>=1)n^=g;return n;}
int main(void){unsigned int g=gray(13U),back=gray_inv(g);printf("c8911 gray=%u,%u\n",g,back);return !(g==11U&&back==13U);}
