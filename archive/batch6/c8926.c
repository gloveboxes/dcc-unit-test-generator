#include <stdio.h>
static int max3(int a,int b,int c){int r=a;if(b>r)r=b;if(c>r)r=c;return r;}
int main(void){printf("c8926 max=%d,%d\n",max3(8,3,5),max3(-1,4,2));return 0;}
