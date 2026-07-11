#include <stdio.h>
static int any_negative(int n,const int a[n]){int i;for(i=0;i<n;++i)if(a[i]<0)return 1;return 0;}
int main(void){int a[4]={1,2,3,4},b[4]={1,-2,3,4};printf("c9914 neg=%d,%d\n",any_negative(4,a),any_negative(4,b));return 0;}
