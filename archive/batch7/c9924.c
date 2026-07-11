#include <stdio.h>
static int find_last(int n,const int a[n],int k){int i;for(i=n-1;i>=0;--i)if(a[i]==k)return i;return -1;}
int main(void){int a[5]={2,4,2,6,2};printf("c9924 last=%d\n",find_last(5,a,2));return 0;}
