#include <stdio.h>
int main(void){int a[6]={1,2,4,8,16,32},i,target=24,low=0,high=5,mid,answer=-1;while(low<=high){mid=(low+high)/2;if(a[mid]>=target){answer=a[mid];high=mid-1;}else low=mid+1;}for(i=0;i<6;++i)if(a[i]==answer)break;printf("c8916 lowerbound=%d index=%d\n",answer,i);return 0;}
