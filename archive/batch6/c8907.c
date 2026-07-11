#include <stdio.h>
static int round_div(int n,int d){return n>=0?(n+d/2)/d:(n-d/2)/d;}
int main(void){printf("c8907 divide=%d,%d\n",round_div(17,5),round_div(-17,5));return 0;}
