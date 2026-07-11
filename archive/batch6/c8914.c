#include <stdio.h>
static int digit_product(int n){int r=1;while(n){r*=n%10;n/=10;}return r;}
int main(void){printf("c8914 product=%d,%d\n",digit_product(234),digit_product(105));return 0;}
