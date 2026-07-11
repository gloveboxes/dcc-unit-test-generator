#include <stdio.h>
static int sum_digits(int n){int r=0;while(n){r+=n%10;n/=10;}return r;}
int main(void){printf("c8913 sumdigits=%d,%d\n",sum_digits(4096),sum_digits(999));return 0;}
