#include <stdio.h>
static int nth_prime(int n){int c=0,i=2;while(1){int j,p=1;for(j=2;j*j<=i;++j)if(i%j==0){p=0;break;}if(p&&++c==n)return i;++i;}}
int main(void){printf("c8904 nprime=%d,%d\n",nth_prime(5),nth_prime(10));return 0;}
