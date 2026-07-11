#include <stdio.h>
struct Packet{int kind;int length;char data[4];};
static struct Packet make_packet(int kind,const char *data){struct Packet p={.kind=kind,.length=0,.data={0,0,0,0}};int i;for(i=0;i<4&&data[i]!='\0';++i){p.data[i]=data[i];++p.length;}return p;}
int main(void){struct Packet p=make_packet(7,"ABCD");printf("c9912 packet=%d/%d/%c%c\n",p.kind,p.length,p.data[0],p.data[3]);return 0;}
