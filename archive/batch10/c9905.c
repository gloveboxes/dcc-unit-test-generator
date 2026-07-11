#include <stdio.h>

struct Phasor { int real,imag; };
static struct Phasor multiply(const struct Phasor *a,const struct Phasor *b){struct Phasor r={.real=a->real*b->real-a->imag*b->imag,.imag=a->real*b->imag+a->imag*b->real};return r;}
int main(void){struct Phasor r=multiply(&(struct Phasor){3,4},&(struct Phasor){-2,5});int energy=r.real*r.real+r.imag*r.imag;printf("c9905 phasor=%d,%d,%d\n",r.real,r.imag,energy);return !(r.real==-26&&r.imag==7&&energy==725);}
