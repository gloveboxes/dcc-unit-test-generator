#include <stdio.h>
struct Color{union{unsigned value;struct{unsigned red;unsigned green;};};};
int main(void){struct Color c;c.red=12;c.green=34;printf("c1102 color=%u,%u\n",c.red,c.green);return 0;}
