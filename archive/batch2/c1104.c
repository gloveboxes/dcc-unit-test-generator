#include <stdio.h>
struct Packet{int type;union{int code;struct{int x;int y;};};};
int main(void){struct Packet p[2]={{1,{.code=404}},{2,{.x=7,.y=8}}};printf("c1104 packet=%d/%d,%d\n",p[0].code,p[1].x,p[1].y);return 0;}
