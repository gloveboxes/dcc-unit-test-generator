#include <stdio.h>
struct Register{union{unsigned long value;struct{unsigned short low;unsigned short high;};};};
int main(void){struct Register r;r.value=0x12345678L;printf("c1114 register=%lX\n",r.value);return 0;}
