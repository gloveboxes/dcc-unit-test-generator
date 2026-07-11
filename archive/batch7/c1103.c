#include <stdio.h>
struct Port{unsigned mode:2;unsigned data:6;};
static void set_data(struct Port* p,unsigned d){p->data=d;}
int main(void){struct Port p={1,0};set_data(&p,40);printf("c1103 port=%u,%u\n",p.mode,p.data);return 0;}
