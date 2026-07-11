#include <stdio.h>
struct Opcode{unsigned group:2;unsigned operation:6;};
static const char *group_name(struct Opcode o){return o.group==0?"math":o.group==1?"io":o.group==2?"flow":"misc";}
int main(void){struct Opcode o={1,17};printf("c1127 opcode=%s,%u\n",group_name(o),o.operation);return 0;}
