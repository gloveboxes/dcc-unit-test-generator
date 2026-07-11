#include <stdio.h>
static int extended_gcd(int a,int b,int *x,int *y){int old_r=a,r=b,old_x=1,cx=0,old_y=0,cy=1,q,t;while(r){q=old_r/r;t=old_r-q*r;old_r=r;r=t;t=old_x-q*cx;old_x=cx;cx=t;t=old_y-q*cy;old_y=cy;cy=t;}*x=old_x;*y=old_y;return old_r;}
int main(void){int x,y,g=extended_gcd(99,78,&x,&y);printf("c8913 egcd=%d,%d\n",g,99*x+78*y);return !(g==3&&99*x+78*y==3);}
