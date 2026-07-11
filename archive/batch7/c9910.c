#include <stdio.h>
static int fold_left(int n,const int a[n],int acc){int i;for(i=0;i<n;++i)acc+=a[i];return acc;}
int main(void){int a[4]={1,2,3,4};printf("c9910 fold=%d\n",fold_left(4,a,10));return 0;}
