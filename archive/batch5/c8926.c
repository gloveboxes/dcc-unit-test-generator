#include <stdio.h>
static int steps(int n){int r=0;while(n!=1){n=n%2?n*3+1:n/2;++r;}return r;}
int main(void){printf("c8926 collatz=%d,%d\n",steps(6),steps(7));return 0;}
