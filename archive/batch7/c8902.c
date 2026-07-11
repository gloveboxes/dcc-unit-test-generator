#include <stdio.h>
static int lcm(int a,int b){int x=a,y=b,t;while(y){t=y;y=x%y;x=t;}return a/x*b;}
int main(void){printf("c8902 lcm=%d,%d\n",lcm(4,6),lcm(21,6));return 0;}
