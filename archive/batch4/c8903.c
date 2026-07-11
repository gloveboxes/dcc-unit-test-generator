#include <stdio.h>
static int lower_bound(const int *a,int n,int key){int first=0,last=n;while(first<last){int middle=(first+last)/2;if(a[middle]<key)first=middle+1;else last=middle;}return first;}
int main(void){int a[6]={2,5,5,8,13,21};printf("c8903 lower=%d,%d\n",lower_bound(a,6,5),lower_bound(a,6,9));return 0;}
