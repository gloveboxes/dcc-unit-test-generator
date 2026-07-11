#include <stdio.h>
static int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a<0?-a:a;}
static int lcm(int a,int b){return a/gcd(a,b)*b;}
int main(void){printf("c8908 lcm=%d,%d\n",lcm(12,18),lcm(14,20));return 0;}
