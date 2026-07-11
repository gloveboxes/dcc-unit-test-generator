#include <stdio.h>
static int power(int b,int e){int r=1;while(e-- > 0)r*=b;return r;}
int main(void){printf("c8905 power=%d,%d\n",power(3,4),power(2,10));return 0;}
