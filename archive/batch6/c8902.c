#include <stdio.h>
static int days(int y,int m){static int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};return d[m]+(m==2&&y%4==0);}
int main(void){printf("c8902 days=%d,%d\n",days(2024,2),days(2025,11));return 0;}
