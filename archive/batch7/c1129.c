#include <stdio.h>
struct ControlBits{unsigned b0:1;unsigned b1:1;unsigned:6;};
static int is_b0(struct ControlBits c){return c.b0;}
int main(void){struct ControlBits c={1,0};printf("c1129 cb=%d\n",is_b0(c));return 0;}
