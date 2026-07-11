#include <stdio.h>

enum LeaseKind { EXCLUSIVE,SHARED };struct Lease { int resource;enum LeaseKind kind;union { struct { int owner,expires; };struct { int readers,latest; }; }; };
static int available(const struct Lease *l,int now){if(l->kind==EXCLUSIVE)return now>=l->expires;return l->readers<3&&now<=l->latest;}
int main(void){struct Lease a={.resource=5,.kind=EXCLUSIVE,.owner=2,.expires=40},b={.resource=7,.kind=SHARED,.readers=2,.latest=50};int x=available(&a,45),y=available(&b,45);printf("c1118 leases=%d,%d,%d\n",x,y,b.readers);return !(x&&y&&b.readers==2);}
