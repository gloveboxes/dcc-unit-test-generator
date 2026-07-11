#include <stdio.h>
#include <stdbool.h>
static bool contains(const int *a,int n,int key){int i;for(i=0;i<n;++i)if(a[i]==key)return true;return false;}
int main(void){int a[5]={4,8,15,16,23};printf("c9911 contains=%d,%d\n",contains(a,5,15),contains(a,5,42));return 0;}
