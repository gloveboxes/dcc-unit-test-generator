#include <stdio.h>
static int digits(int n){int r=0;do{++r;n/=10;}while(n);return r;}
int main(void){printf("c8912 digits=%d,%d\n",digits(0),digits(12345));return 0;}
