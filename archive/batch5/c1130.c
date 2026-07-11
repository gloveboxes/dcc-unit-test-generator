#include <stdio.h>
struct Versioned{struct{unsigned major:4;unsigned minor:4;};unsigned build;};
int main(void){struct Versioned v={.major=3,.minor=1,.build=42};printf("c1130 version=%u.%u/%u\n",v.major,v.minor,v.build);return 0;}
