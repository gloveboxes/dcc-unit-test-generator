#include <stdio.h>
static int seconds(int h,int m,int s){return h*3600+m*60+s;}
int main(void){printf("c9933 time=%d\n",seconds(11,2,10)-seconds(9,45,30));return 0;}
