#include <stdio.h>
static int contains_vla(int n,const int a[n],int key){int i;for(i=0;i<n;++i)if(a[i]==key)return 1;return 0;}
int main(void){int a[5]={2,4,6,8,10};printf("c9902 vla=%d,%d\n",contains_vla(5,a,6),contains_vla(5,a,7));return 0;}
