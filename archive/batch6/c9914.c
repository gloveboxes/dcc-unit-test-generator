#include <stdio.h>
struct Fraction{int n;int d;};
static struct Fraction reduce(struct Fraction f){int a=f.n,b=f.d,t;while(b){t=a%b;a=b;b=t;}f.n/=a;f.d/=a;return f;}
int main(void){struct Fraction f=reduce((struct Fraction){42,56});printf("c9914 fraction=%d/%d\n",f.n,f.d);return 0;}
