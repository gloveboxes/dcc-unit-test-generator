#include <stdio.h>
int main(void){int a[8]={13,17,2,4,6,9,11,12},key=4,lo=0,hi=7,mid,found=-1;while(lo<=hi){mid=(lo+hi)/2;if(a[mid]==key){found=mid;break;}if(a[mid]<key)lo=mid+1;else hi=mid-1;}printf("c8902 search=%d\n",found);return 0;}
