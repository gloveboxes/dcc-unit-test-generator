#include <stdio.h>
struct Status{unsigned busy:1;unsigned code:3;unsigned count:4;};
static int pack(struct Status s){return s.busy|(s.code<<1)|(s.count<<4);}
int main(void){struct Status s={1,5,9};printf("c1107 status=%d\n",pack(s));return 0;}
