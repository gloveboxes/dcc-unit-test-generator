#include <stdio.h>
static int weekday(int y,int m,int d){int t;if(m<3){--y;m+=12;}t=(y+y/4-y/100+y/400+(13*m+8)/5+d)%7;return t;}
int main(void){printf("c8903 weekday=%d,%d\n",weekday(2024,1,1),weekday(2024,7,4));return 0;}
