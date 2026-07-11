#include <stdio.h>
static int sqrt_int(int n){int r=0;while((r+1)*(r+1)<=n)++r;return r;}
int main(void){printf("c8908 sqrt=%d,%d\n",sqrt_int(49),sqrt_int(63));return 0;}
