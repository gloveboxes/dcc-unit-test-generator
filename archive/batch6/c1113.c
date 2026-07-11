#include <stdio.h>
struct Mode{unsigned value:2;};
static const char *name(struct Mode m){return m.value==0?"idle":m.value==1?"run":m.value==2?"wait":"fault";}
int main(void){struct Mode m={2};printf("c1113 mode=%s\n",name(m));return 0;}
