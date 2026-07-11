#include <stdio.h>
static int find_first(int n,const int a[n],int key){int i;for(i=0;i<n;++i)if(a[i]==key)return i;return -1;}
int main(void){int a[5]={4,8,15,16,23};printf("c9918 find=%d,%d\n",find_first(5,a,15),find_first(5,a,42));return 0;}
