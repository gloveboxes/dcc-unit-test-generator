#include <stdio.h>
static int fact(int n){int r=1;while(n>1)r*=n--;return r;}
int main(void){printf("c8906 fact=%d,%d\n",fact(5),fact(7));return 0;}
