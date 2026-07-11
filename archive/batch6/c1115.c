#include <stdio.h>
struct Control{unsigned enable:1;unsigned interrupt:1;unsigned priority:2;unsigned reserved:4;};
int main(void){struct Control c={1,1,2,0};printf("c1115 control=%u,%u,%u\n",c.enable,c.interrupt,c.priority);return 0;}
