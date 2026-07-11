#include <stdio.h>
struct Color16{union{unsigned value;struct{unsigned red:5;unsigned green:6;unsigned blue:5;};};};
int main(void){struct Color16 c={.red=12,.green=34,.blue=7};printf("c1123 rgb=%u,%u,%u\n",c.red,c.green,c.blue);return 0;}
