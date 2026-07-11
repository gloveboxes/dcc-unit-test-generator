#include <stdio.h>
struct Fraction{int n;int d;};
static int gcd(int a,int b){int t;while(b){t=a%b;a=b;b=t;}return a<0?-a:a;}
static struct Fraction add(struct Fraction a,struct Fraction b){struct Fraction r;int g;r.n=a.n*b.d+b.n*a.d;r.d=a.d*b.d;g=gcd(r.n,r.d);r.n/=g;r.d/=g;return r;}
int main(void){struct Fraction a={2,3},b={5,12},r;r=add(a,b);printf("c8915 fraction=%d/%d\n",r.n,r.d);return 0;}
