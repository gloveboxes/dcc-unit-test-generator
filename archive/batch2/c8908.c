#include <stdio.h>
int main(void){int a[5]={2,7,1,8,2},b[5]={8,1,8,2,8},i,carry=0,result=0;for(i=4;i>=0;--i){carry=a[i]+b[i]+carry;result=(result+carry%10);carry/=10;}printf("c8908 digitsum=%d carry=%d\n",result,carry);return 0;}
