#include <stdio.h>
static int moves;
static void hanoi(int n,char from,char to,char spare){if(n==0)return;hanoi(n-1,from,spare,to);++moves;hanoi(n-1,spare,to,from);}
int main(void){moves=0;hanoi(5,'A','C','B');printf("c8913 hanoi=%d\n",moves);return 0;}
