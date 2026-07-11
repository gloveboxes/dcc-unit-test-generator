#include <stdio.h>
struct Color{unsigned red:5;unsigned green:6;unsigned blue:5;};
int main(void){struct Color c={17,33,9};unsigned packed=(c.red<<11)|(c.green<<5)|c.blue;printf("c9910 bitfield=%X\n",packed);return 0;}
