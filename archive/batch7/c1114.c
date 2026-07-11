#include <stdio.h>
struct SysReg{union{struct{unsigned f1:1;unsigned f2:1;unsigned f3:1;unsigned unused:5;};unsigned char b;};};
int main(void){struct SysReg s;s.b=0;s.f1=1;s.f3=1;printf("c1114 sys=%x\n",s.b);return 0;}
