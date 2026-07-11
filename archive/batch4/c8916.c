#include <stdio.h>
static int longest_run(const int *a,int n){int best=0,current=0,i;for(i=0;i<n;++i){if(a[i])++current;else current=0;if(current>best)best=current;}return best;}
int main(void){int bits[10]={1,1,0,1,1,1,0,1,0,0};printf("c8916 run=%d\n",longest_run(bits,10));return 0;}
