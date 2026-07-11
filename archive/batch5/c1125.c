#include <stdio.h>
struct Packet{int kind;union{struct{int x;int y;};int code;};};
int main(void){struct Packet p={.kind=1,.x=3,.y=4};printf("c1125 packet=%d\n",p.x+p.y);return 0;}
