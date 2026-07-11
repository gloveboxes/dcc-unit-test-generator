#include <stdio.h>
struct Fraction { int num,den; };
static int gcd(int a,int b){while(b){int next=a%b;a=b;b=next;}return a;}
static void reduce(struct Fraction *f){int d=gcd(f->num<0?-f->num:f->num,f->den);f->num/=d;f->den/=d;}
static struct Fraction add(const struct Fraction *a,const struct Fraction *b){struct Fraction result={.num=a->num*b->den+b->num*a->den,.den=a->den*b->den};reduce(&result);return result;}
int main(void){struct Fraction value=add(&(struct Fraction){1,6},&(struct Fraction){1,4});printf("c9922 fraction=%d/%d\n",value.num,value.den);return !(value.num==5&&value.den==12);}
