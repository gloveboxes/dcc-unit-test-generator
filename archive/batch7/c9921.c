#include <stdio.h>
static int intersect_vla(int n,const int a[n],const int b[n]){int i,j,r=0;for(i=0;i<n;++i)for(j=0;j<n;++j)if(a[i]==b[j])++r;return r;}
int main(void){int a[4]={1,2,3,4},b[4]={3,4,5,6};printf("c9921 int=%d\n",intersect_vla(4,a,b));return 0;}
