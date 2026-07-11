#include <stdio.h>
struct Fraction{int num;int den;};
static struct Fraction add_frac(struct Fraction a,struct Fraction b){return (struct Fraction){a.num*b.den+b.num*a.den,a.den*b.den};}
int main(void){struct Fraction f=add_frac((struct Fraction){1,2},(struct Fraction){1,3});printf("c9909 frac=%d/%d\n",f.num,f.den);return 0;}
