#include <stdio.h>
static int reverse(int n){int r=0;while(n){r=r*10+n%10;n/=10;}return r;}
int main(void){printf("c8902 reverse=%d,%d\n",reverse(12030),reverse(9876));return 0;}
