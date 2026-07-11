#include <stdio.h>
struct Option{int is_some;union{int val;};};
static int get_opt(struct Option o){return o.is_some?o.val:-1;}
int main(void){printf("c1131 opt=%d\n",get_opt((struct Option){1,{10}}));return 0;}
