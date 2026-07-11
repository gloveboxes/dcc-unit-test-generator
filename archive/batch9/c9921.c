#include <stdio.h>
static const int month_days[13]={[1]=31,[2]=28,[3]=31,[4]=30,[5]=31,[6]=30,[7]=31,[8]=31,[9]=30,[10]=31,[11]=30,[12]=31};
static int quarter_days(int quarter){int total=0;for(int month=(quarter-1)*3+1;month<=quarter*3;++month)total+=month_days[month];return total;}
int main(void){int q1=quarter_days(1),q4=quarter_days(4);printf("c9921 quarters=%d,%d\n",q1,q4);return !(q1==90&&q4==92);}
