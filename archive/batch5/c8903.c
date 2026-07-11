#include <stdio.h>
static int gcd(int a,int b){int t;while(b){t=a%b;a=b;b=t;}return a;}
int main(void){printf("c8903 gcd=%d,%d\n",gcd(84,30),gcd(121,44));return 0;}
