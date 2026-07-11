#include <stdio.h>
struct Color{union{unsigned value;struct{unsigned red;unsigned green;unsigned blue;};};};
static unsigned brightness(struct Color color){return color.red+color.green+color.blue;}
int main(void){struct Color color={.red=12,.green=34,.blue=56};printf("c1112 color=%u,%u\n",brightness(color),color.green);return 0;}
