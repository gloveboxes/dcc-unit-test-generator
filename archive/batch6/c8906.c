#include <stdio.h>
static int contains(int a,int b,int x){return x>=a&&x<=b;}
int main(void){printf("c8906 interval=%d,%d\n",contains(4,12,9),contains(4,12,13));return 0;}
