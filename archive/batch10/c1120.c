#include <stdio.h>

enum NodeKind { LITERAL,RANGE,REPEAT };struct Node { enum NodeKind kind;union { int value;struct { int low,high; };struct { int child,count; }; }; };
static int matches(const struct Node *n,int input){if(n->kind==LITERAL)return input==n->value;if(n->kind==RANGE)return input>=n->low&&input<=n->high;return input==n->child&&n->count>0;}
int main(void){struct Node a={.kind=LITERAL,.value=7},b={.kind=RANGE,.low=10,.high=20},c={.kind=REPEAT,.child=4,.count=3};int mask=matches(&a,7)*4+matches(&b,15)*2+matches(&c,5);printf("c1120 nodes=%d,%d\n",mask,c.count);return !(mask==6&&c.count==3);}
