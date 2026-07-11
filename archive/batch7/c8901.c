#include <stdio.h>
static int gcd(int a,int b){int t;while(b){t=b;b=a%b;a=t;}return a;}
int main(void){printf("c8901 gcd=%d,%d\n",gcd(48,18),gcd(101,10));return 0;}
