#include <stdio.h>
#include <stdint.h>

/* The word overlay assumes little-endian layout, shared by Z80 and the host. */
union Tile { uint16_t packed; struct { unsigned x:5;unsigned y:5;unsigned layer:3;unsigned blocked:1;unsigned reserved:2; }; };
static int distance(union Tile a,union Tile b){int dx=(int)a.x-(int)b.x,dy=(int)a.y-(int)b.y;return (dx<0?-dx:dx)+(dy<0?-dy:dy)+(a.layer==b.layer?0:4);}
int main(void){union Tile a={.x=3,.y=7,.layer=2},b={.x=12,.y=4,.layer=3,.blocked=1};int d=distance(a,b);printf("c1114 tiles=%d,%u,%u\n",d,(unsigned)b.blocked,(unsigned)a.layer);return !(d==16&&b.blocked==1U&&a.layer==2U);}
