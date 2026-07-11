#include <stdio.h>
#include <stdbool.h>

static bool monotonic(const int *a,int n){if(n<3)return true;int direction=0;for(int i=1;i<n;++i){int delta=a[i]-a[i-1];if(delta&&direction&&((delta>0)!=(direction>0)))return false;if(delta&&!direction)direction=delta;}return true;}
int main(void){int a[7]={2,2,4,7,7,9,12},b[6]={8,6,6,3,5,1};bool x=monotonic(a,7),y=monotonic(b,6);printf("c9930 monotonic=%d,%d\n",(int)x,(int)y);return !(x&&!y);}
