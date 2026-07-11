#include <stdio.h>
#include <stdbool.h>
static bool nondecreasing(int n,const int a[n]){int i;for(i=1;i<n;++i)if(a[i]<a[i-1])return false;return true;}
int main(void){int a[4]={1,2,2,5},b[3]={1,3,2};printf("c9926 order=%d,%d\n",nondecreasing(4,a),nondecreasing(3,b));return 0;}
