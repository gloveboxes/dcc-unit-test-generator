#include <stdio.h>
struct Version{union{unsigned value;struct{unsigned major:4;unsigned minor:4;unsigned patch:8;};};};
int main(void){struct Version v={.major=2,.minor=5,.patch=19};printf("c1105 version=%u.%u.%u\n",v.major,v.minor,v.patch);return 0;}
