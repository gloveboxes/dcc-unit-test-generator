#include <stdio.h>
static int unique(int n,const int a[n]){int i,j;for(i=0;i<n;++i)for(j=i+1;j<n;++j)if(a[i]==a[j])return 0;return 1;}
int main(void){int a[4]={1,2,3,4},b[4]={1,2,1,4};printf("c9931 unique=%d,%d\n",unique(4,a),unique(4,b));return 0;}
