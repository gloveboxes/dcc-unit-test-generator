#include <stdio.h>
static int leap(int y){return y%4==0&&(y%100!=0||y%400==0);}
int main(void){printf("c8901 leap=%d,%d\n",leap(2024),leap(2100));return 0;}
