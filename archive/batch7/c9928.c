#include <stdio.h>
static int min_max_diff(int n,const int a[n]){int i,min=a[0],max=a[0];for(i=1;i<n;++i){if(a[i]<min)min=a[i];if(a[i]>max)max=a[i];}return max-min;}
int main(void){int a[5]={7,2,9,1,5};printf("c9928 mmdiff=%d\n",min_max_diff(5,a));return 0;}
