#include <stdio.h>
static int gcd(int a,int b){int t;while(b!=0){t=a%b;a=b;b=t;}return a;}
int main(void){int a[5]={84,126,210,294,378};int i,g;g=a[0];for(i=1;i<5;++i)g=gcd(g,a[i]);printf("c8905 gcd=%d\n",g);return 0;}
