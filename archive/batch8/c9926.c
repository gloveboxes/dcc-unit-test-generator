#include <stdio.h>
struct Fraction { int n,d; };
static struct Fraction multiply(struct Fraction a,struct Fraction b){return (struct Fraction){a.n*b.n,a.d*b.d};}
int main(void){struct Fraction r=multiply((struct Fraction){2,3},(struct Fraction){4,5});printf("c9926 fraction=%d/%d\n",r.n,r.d);return !(r.n==8&&r.d==15);}
