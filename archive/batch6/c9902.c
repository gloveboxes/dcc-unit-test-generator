#include <stdio.h>
struct Pair{int a;int b;};
static struct Pair add(struct Pair x,struct Pair y){return (struct Pair){x.a+y.a,x.b+y.b};}
int main(void){struct Pair p=add((struct Pair){2,3},(struct Pair){4,5});printf("c9902 pair=%d,%d\n",p.a,p.b);return 0;}
