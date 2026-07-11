#include <stdio.h>
static int binary(const int *a,int n,int key){int lo=0,hi=n-1,mid;while(lo<=hi){mid=(lo+hi)/2;if(a[mid]==key)return mid;if(a[mid]<key)lo=mid+1;else hi=mid-1;}return -1;}
int main(void){int a[6]={1,4,8,15,16,23};printf("c8907 search=%d,%d\n",binary(a,6,15),binary(a,6,9));return 0;}
