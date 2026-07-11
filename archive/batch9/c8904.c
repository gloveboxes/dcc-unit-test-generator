#include <stdio.h>
static int merge(const int a[],int na,const int b[],int nb,int out[],int cap){int ia=0,ib=0,n=0;if(na+nb>cap)return -1;while(ia<na&&ib<nb)out[n++]=a[ia]<=b[ib]?a[ia++]:b[ib++];while(ia<na)out[n++]=a[ia++];while(ib<nb)out[n++]=b[ib++];return n;}
int main(void){int a[3]={1,4,8},b[4]={2,3,7,9},out[7];int n=merge(a,3,b,4,out,7);printf("c8904 merge=%d,%d,%d\n",n,out[0],out[6]);return !(n==7&&out[0]==1&&out[6]==9);}
