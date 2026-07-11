#include <stdio.h>
static int median(int a,int b,int c){if(a>b){int t=a;a=b;b=t;}if(b>c){int t=b;b=c;c=t;}if(a>b)b=a;return b;}
int main(void){printf("c8918 median=%d,%d\n",median(9,2,5),median(1,7,4));return 0;}
