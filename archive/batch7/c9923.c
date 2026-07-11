#include <stdio.h>
static int is_sorted(int n,const int a[n]){int i;for(i=1;i<n;++i)if(a[i]<a[i-1])return 0;return 1;}
int main(void){int a[4]={1,2,3,4},b[4]={1,3,2,4};printf("c9923 sort=%d,%d\n",is_sorted(4,a),is_sorted(4,b));return 0;}
