#include <stdio.h>
static const unsigned char days[13]={[1]=31,[2]=28,[3]=31,[4]=30,[5]=31,[6]=30,[7]=31,[8]=31,[9]=30,[10]=31,[11]=30,[12]=31};
int main(void) { int quarter=days[4]+days[5]+days[6]; printf("c9925 quarter=%d\n",quarter); return quarter!=91; }
