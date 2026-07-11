#include <stdio.h>
static int selectk(const int *a,int n,int k){int b[8],i,j,v;for(i=0;i<n;++i)b[i]=a[i];for(i=1;i<n;++i){v=b[i];j=i;while(j&&b[j-1]>v){b[j]=b[j-1];--j;}b[j]=v;}return b[k];}
int main(void){int a[7]={12,4,9,1,20,7,6};printf("c8932 select=%d\n",selectk(a,7,3));return 0;}
