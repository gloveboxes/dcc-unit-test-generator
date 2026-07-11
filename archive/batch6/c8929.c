#include <stdio.h>
static int clamp(int n,int lo,int hi){if(n<lo)return lo;if(n>hi)return hi;return n;}
int main(void){printf("c8929 clamp=%d,%d,%d\n",clamp(-1,0,5),clamp(3,0,5),clamp(9,0,5));return 0;}
