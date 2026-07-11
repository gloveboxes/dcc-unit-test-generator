#include <stdio.h>
static int is_armstrong(int n){int x=n,r=0,d;while(x){d=x%10;r+=d*d*d;x/=10;}return r==n;}
int main(void){printf("c8915 armstrong=%d,%d\n",is_armstrong(153),is_armstrong(154));return 0;}
