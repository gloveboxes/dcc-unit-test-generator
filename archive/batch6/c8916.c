#include <stdio.h>
static int proper_sum(int n){int i,r=1;if(n==1)return 0;for(i=2;i*i<=n;++i)if(n%i==0){r+=i;if(i*i!=n)r+=n/i;}return r;}
int main(void){printf("c8916 perfect=%d,%d\n",proper_sum(6),proper_sum(12));return 0;}
