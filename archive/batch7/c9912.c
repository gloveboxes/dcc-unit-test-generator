#include <stdio.h>
static int all_odd(int n,const int a[n]){int i;for(i=0;i<n;++i)if(a[i]%2==0)return 0;return 1;}
int main(void){int a[3]={1,3,5},b[3]={1,2,5};printf("c9912 odd=%d,%d\n",all_odd(3,a),all_odd(3,b));return 0;}
