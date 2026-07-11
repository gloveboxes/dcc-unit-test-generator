#include <stdio.h>
struct Rgb{union{unsigned value;struct{unsigned red:5;unsigned green:6;unsigned blue:5;};};};
int main(void){struct Rgb c;c.red=12;c.green=34;c.blue=7;printf("c1105 rgb=%u,%u,%u\n",c.red,c.green,c.blue);return 0;}
