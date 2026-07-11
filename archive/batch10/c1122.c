#include <stdio.h>

enum ResponseKind { ACCEPTED,REDIRECT,REJECTED };struct Response { int request;enum ResponseKind kind;union { struct { int slot,quota; };struct { int node,cost; };struct { int reason,retryAfter; }; }; };
static int value(const struct Response *r){if(r->kind==ACCEPTED)return r->slot+r->quota;if(r->kind==REDIRECT)return r->node-r->cost;return r->retryAfter-r->reason;}
int main(void){struct Response r[3]={{.request=1,.kind=ACCEPTED,.slot=4,.quota=20},{.request=2,.kind=REDIRECT,.node=12,.cost=3},{.request=3,.kind=REJECTED,.reason=5,.retryAfter=14}};int total=0;for(int i=0;i<3;++i)total+=value(&r[i]);printf("c1122 responses=%d,%d\n",total,r[2].reason);return !(total==42&&r[2].reason==5);}
