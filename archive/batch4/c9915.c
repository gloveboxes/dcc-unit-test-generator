#include <stdio.h>
static int rotate_left(unsigned value,int count){unsigned mask;mask=1<<15;while(count--){value=(value<<1)|((value&mask)!=0);value&=65535;}return (int)value;}
int main(void){printf("c9915 rotate=%d,%d\n",rotate_left(1,4),rotate_left(32768,1));return 0;}
