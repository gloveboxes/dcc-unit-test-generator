#include <stdio.h>
#include <stdbool.h>
static bool between(int n,int lo,int hi){return n>=lo&&n<=hi;}
int main(void){printf("c9903 bool=%d,%d\n",between(5,1,9),between(12,1,9));return 0;}
