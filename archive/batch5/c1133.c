#include <stdio.h>
struct Frame{union{unsigned long raw;struct{unsigned short low;unsigned short high;};};};
int main(void){struct Frame f;f.raw=0x00030007L;printf("c1133 frame=%lX\n",f.raw);return 0;}
