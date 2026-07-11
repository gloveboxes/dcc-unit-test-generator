#include <stdio.h>
static int find_max_index(int n,const int a[n]){int i,mi=0;for(i=1;i<n;++i)if(a[i]>a[mi])mi=i;return mi;}
int main(void){int a[5]={2,8,1,9,4};printf("c9917 maxidx=%d\n",find_max_index(5,a));return 0;}
