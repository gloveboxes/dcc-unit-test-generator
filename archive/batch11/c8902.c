#include <stdio.h>
#define DIGITS 8
static int bigadd(const int a[],const int b[],int out[],int n){int carry=0,i;for(i=0;i<n;++i){int sum=a[i]+b[i]+carry;out[i]=sum%10;carry=sum/10;}return carry;}
int main(void){int a[DIGITS]={9,9,9,3,0,0,0,0},b[DIGITS]={1,0,0,0,0,0,0,0},out[DIGITS];int carry=bigadd(a,b,out,DIGITS);printf("c8902 bigadd=%d%d%d%d,%d\n",out[3],out[2],out[1],out[0],carry);return !(out[0]==0&&out[3]==4&&carry==0);}
