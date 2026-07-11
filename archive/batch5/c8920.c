#include <stdio.h>
static int digit_sum(int n){int r=0;while(n){r+=n%10;n/=10;}return r;}
int main(void){printf("c8920 digitsum=%d,%d\n",digit_sum(4096),digit_sum(12345));return 0;}
