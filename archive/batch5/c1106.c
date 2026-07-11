#include <stdio.h>
struct Color{union{unsigned value;struct{unsigned red;unsigned green;unsigned blue;};};};
int main(void){struct Color c={.red=10,.green=20,.blue=30};printf("c1106 color=%u,%u,%u\n",c.red,c.green,c.blue);return 0;}
