#include <stdio.h>
static int majority(int a,int b,int c){return a+b+c>=2;}
int main(void){printf("c8924 majority=%d,%d\n",majority(1,1,0),majority(1,0,0));return 0;}
