#include <stdio.h>

enum TxKind { RECEIVE,ISSUE,TRANSFER };struct Transaction { int item;enum TxKind kind;union { int quantity;struct { int from,to,count; }; }; };
static int delta(const struct Transaction *t,int warehouse){if(t->kind==RECEIVE)return t->quantity;if(t->kind==ISSUE)return -t->quantity;if(t->from==warehouse)return -t->count;if(t->to==warehouse)return t->count;return 0;}
int main(void){struct Transaction t[3]={{.item=4,.kind=RECEIVE,.quantity=20},{.item=4,.kind=ISSUE,.quantity=6},{.item=4,.kind=TRANSFER,.from=2,.to=5,.count=7}};int stock=10;for(int i=0;i<3;++i)stock+=delta(&t[i],2);printf("c1123 stock=%d,%d\n",stock,t[2].to);return !(stock==17&&t[2].to==5);}
