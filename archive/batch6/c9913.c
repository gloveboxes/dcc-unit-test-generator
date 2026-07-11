#include <stdio.h>
static int all_positive(int n,const int a[n]){int i;for(i=0;i<n;++i)if(a[i]<=0)return 0;return 1;}
int main(void){int a[3]={1,2,3},b[3]={1,-2,3};printf("c9913 positive=%d,%d\n",all_positive(3,a),all_positive(3,b));return 0;}
