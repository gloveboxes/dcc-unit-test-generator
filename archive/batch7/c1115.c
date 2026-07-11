#include <stdio.h>
struct KeyVal{unsigned k:4;unsigned v:12;};
static int get_v(struct KeyVal kv){return kv.v;}
int main(void){printf("c1115 kv=%d\n",get_v((struct KeyVal){10,2048}));return 0;}
