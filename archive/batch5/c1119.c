#include <stdio.h>
struct Measure{int kind;union{int count;float ratio;};};
int main(void){struct Measure m={.kind=1,.count=42};printf("c1119 measure=%d,%d\n",m.kind,m.count);return 0;}
