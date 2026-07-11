#include <stdio.h>
static int select_k(const int *a,int n,int k){int sorted[8],i,j,value;for(i=0;i<n;++i)sorted[i]=a[i];for(i=1;i<n;++i){value=sorted[i];j=i;while(j&&sorted[j-1]>value){sorted[j]=sorted[j-1];--j;}sorted[j]=value;}return sorted[k];}
int main(void){int a[7]={12,4,9,1,20,7,6};printf("c8912 median=%d\n",select_k(a,7,3));return 0;}
