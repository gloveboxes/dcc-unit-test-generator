#include <stdio.h>
static int is_square(int n){int i;for(i=0;i*i<=n;++i)if(i*i==n)return 1;return 0;}
int main(void){printf("c8917 square=%d,%d\n",is_square(144),is_square(145));return 0;}
