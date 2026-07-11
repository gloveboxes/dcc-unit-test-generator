#include <stdio.h>
struct Entry{int index;int value;};
static long sparse_dot(const struct Entry a[],int na,const struct Entry b[],int nb){int ia=0,ib=0;long total=0L;while(ia<na&&ib<nb){if(a[ia].index==b[ib].index){total+=(long)a[ia].value*b[ib].value;++ia;++ib;}else if(a[ia].index<b[ib].index)++ia;else ++ib;}return total;}
int main(void){struct Entry a[3]={{1,4},{4,2},{8,3}},b[3]={{0,9},{4,5},{8,-1}};long actual=sparse_dot(a,3,b,3);printf("c8923 sparse=%ld\n",actual);return actual!=7L;}
