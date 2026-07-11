#include <stdio.h>
static void dutch_flag(int a[],int n){int lo=0,mid=0,hi=n-1,t;while(mid<=hi){if(a[mid]==0){t=a[lo];a[lo++]=a[mid];a[mid++]=t;}else if(a[mid]==1)++mid;else{t=a[mid];a[mid]=a[hi];a[hi--]=t;}}}
int main(void){int a[8]={2,0,1,2,1,0,1,2};dutch_flag(a,8);printf("c8924 dutch=%d%d%d%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);return !(a[0]==0&&a[2]==1&&a[5]==2);}
