#include <stdio.h>
static int median3(int a,int b,int c){if(a>b){int t=a;a=b;b=t;}if(b>c){int t=b;b=c;c=t;}if(a>b){int t=a;a=b;b=t;}return b;}
int main(void){int a=median3(9,2,6),b=median3(-1,4,0);printf("c8925 median=%d,%d\n",a,b);return !(a==6&&b==0);}
