#include <stdio.h>
static int power(int b,int e){int r=1;while(e--){r*=b;}return r;}
int main(void){printf("c8909 pow=%d,%d\n",power(2,5),power(3,4));return 0;}
