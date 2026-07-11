#include <stdio.h>
static int overlap(int a,int b,int c,int d){int lo=a>c?a:c,hi=b<d?b:d;return hi>lo?hi-lo:0;}
int main(void){printf("c8905 overlap=%d,%d\n",overlap(2,9,5,12),overlap(1,3,4,8));return 0;}
