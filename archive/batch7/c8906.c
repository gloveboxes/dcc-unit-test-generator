#include <stdio.h>
static int collatz(int n){int r=0;while(n>1){if(n%2==0)n/=2;else n=n*3+1;++r;}return r;}
int main(void){printf("c8906 collatz=%d,%d\n",collatz(6),collatz(12));return 0;}
