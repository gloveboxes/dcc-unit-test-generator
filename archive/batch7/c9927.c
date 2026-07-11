#include <stdio.h>
#include <stdbool.h>
static bool has_dups(int n,const int a[n]){int i,j;for(i=0;i<n;++i)for(j=i+1;j<n;++j)if(a[i]==a[j])return true;return false;}
int main(void){int a[4]={1,2,3,4},b[4]={1,2,1,4};printf("c9927 dup=%d,%d\n",has_dups(4,a),has_dups(4,b));return 0;}
