#include <stdio.h>
static int interpolate(int a,int b,int percent){return a+(b-a)*percent/100;}
int main(void){printf("c8930 lerp=%d,%d\n",interpolate(10,30,25),interpolate(-10,10,75));return 0;}
