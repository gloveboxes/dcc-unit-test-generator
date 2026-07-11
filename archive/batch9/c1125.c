#include <stdio.h>
struct Pose { union { struct { int x,y; }; int position[2]; }; union { struct { int dx,dy; }; int velocity[2]; }; };
static void advance(struct Pose *pose,int ticks){pose->x+=pose->dx*ticks;pose->y+=pose->dy*ticks;}
int main(void){struct Pose pose={.position={4,7},.velocity={3,-2}};advance(&pose,5);printf("c1125 pose=%d,%d\n",pose.x,pose.y);return !(pose.x==19&&pose.y==-3);}
