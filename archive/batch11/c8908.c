#include <stdio.h>
#define MAX 8
static int merge_intervals(int starts[],int ends[],int n,int os[],int oe[]){int i,k=0;if(n==0)return 0;int cs=starts[0],ce=ends[0];for(i=1;i<n;++i){if(starts[i]<=ce){if(ends[i]>ce)ce=ends[i];}else{os[k]=cs;oe[k++]=ce;cs=starts[i];ce=ends[i];}}os[k]=cs;oe[k++]=ce;return k;}
int main(void){int s[5]={1,2,8,15,16},e[5]={3,6,10,18,17},os[5],oe[5];int k=merge_intervals(s,e,5,os,oe);printf("c8908 intervals=%d,%d-%d\n",k,os[0],oe[0]);return !(k==3&&os[0]==1&&oe[0]==6);}
