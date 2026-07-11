#include <stdio.h>
static int dig_root(int n){int r=n%9;return r?r:n?9:0;}
int main(void){printf("c8911 root=%d,%d\n",dig_root(12345),dig_root(99));return 0;}
