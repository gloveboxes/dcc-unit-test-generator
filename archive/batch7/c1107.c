#include <stdio.h>
struct CPUFlags{unsigned c:1;unsigned z:1;unsigned s:1;unsigned o:1;unsigned p:1;unsigned res:3;};
static int is_zero(struct CPUFlags f){return f.z;}
int main(void){struct CPUFlags f={0,1,0,0,0,0};printf("c1107 flag=%d\n",is_zero(f));return 0;}
