#include <stdio.h>
static int clamp(int v,int lo,int hi){return v<lo?lo:v>hi?hi:v;}
int main(void){printf("c8915 clamp=%d,%d,%d\n",clamp(-2,0,9),clamp(4,0,9),clamp(20,0,9));return 0;}
