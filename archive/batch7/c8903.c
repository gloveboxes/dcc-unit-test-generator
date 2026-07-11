#include <stdio.h>
static int is_prime(int n){int i;if(n<2)return 0;for(i=2;i*i<=n;++i)if(n%i==0)return 0;return 1;}
int main(void){printf("c8903 prime=%d,%d\n",is_prime(17),is_prime(25));return 0;}
