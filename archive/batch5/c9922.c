#include <stdio.h>
static int triangular(int n){int i,r=0;for(i=1;i<=n;++i)r+=i;return r;}
int main(void){printf("c9922 triangle=%d,%d\n",triangular(10),triangular(20));return 0;}
