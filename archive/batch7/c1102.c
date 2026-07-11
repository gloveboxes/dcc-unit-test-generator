#include <stdio.h>
struct TaggedNode{int val;union{int tag;};};
static int get_val(struct TaggedNode n){return n.val;}
int main(void){struct TaggedNode n={42,{0}};printf("c1102 node=%d\n",get_val(n));return 0;}
