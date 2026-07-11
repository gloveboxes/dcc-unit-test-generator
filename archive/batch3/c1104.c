#include <stdio.h>
struct Flags{union{unsigned value;struct{unsigned ready:1;unsigned error:1;unsigned mode:2;};};};
int main(void){struct Flags f={.ready=1,.error=0,.mode=2};printf("c1104 flags=%u/%u,%u,%u\n",f.value,f.ready,f.error,f.mode);return 0;}
