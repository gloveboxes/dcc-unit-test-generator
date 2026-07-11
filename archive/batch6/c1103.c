#include <stdio.h>
struct Flags{unsigned ready:1;unsigned error:1;unsigned mode:2;};
int main(void){struct Flags f={1,0,3};printf("c1103 flags=%u,%u,%u\n",f.ready,f.error,f.mode);return 0;}
