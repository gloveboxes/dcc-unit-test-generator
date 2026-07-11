#include <stdio.h>
#include <stdbool.h>
static bool subset(int count,const int values[count],int target){bool possible[target+1];for(int sum=0;sum<=target;++sum)possible[sum]=false;possible[0]=true;for(int i=0;i<count;++i)for(int sum=target;sum>=values[i];--sum)if(possible[sum-values[i]])possible[sum]=true;return possible[target];}
int main(void){int values[5]={3,7,9,12,4};bool a=subset(5,values,16),b=subset(5,values,2);printf("c9931 subset=%d,%d\n",(int)a,(int)b);return !(a&&!b);}
