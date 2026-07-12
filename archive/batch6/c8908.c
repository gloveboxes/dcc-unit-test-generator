#include <stdio.h>
static long fixed_mul(long a,long b){return (a*b+50L)/100L;}
int main(void){printf("c8908 fixed=%ld,%ld\n",fixed_mul(125L,80L),fixed_mul(333L,250L));return 0;}
