#include <stdio.h>
static int maxrun(const int *a,int n){int i,r=0,c=0;for(i=0;i<n;++i){if(a[i])++c;else c=0;if(c>r)r=c;}return r;}
int main(void){int a[8]={1,1,0,1,1,1,0,1};printf("c8916 maxrun=%d\n",maxrun(a,8));return 0;}
