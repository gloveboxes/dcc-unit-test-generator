#include <stdio.h>
struct Filter{enum{F_ALL,F_NONE} t;union{int dummy;};};
static int allow(struct Filter f){return f.t==F_ALL;}
int main(void){printf("c1106 filt=%d\n",allow((struct Filter){F_ALL,{0}}));return 0;}
