#include <stdio.h>
struct State{unsigned active:1;unsigned code:7;};
static struct State set_code(struct State s,unsigned code){s.code=code&127;s.active=1;return s;}
int main(void){struct State s={0,0};s=set_code(s,200);printf("c1130 state=%u,%u\n",s.active,s.code);return 0;}
