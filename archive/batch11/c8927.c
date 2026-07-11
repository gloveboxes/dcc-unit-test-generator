#include <stdio.h>
static int hanoi_moves(int n){int i,count=0;for(i=0;i<n;++i)count=(count*2)+1;return count;}
static void hanoi(int n,char from,char to,char aux,int *count){if(n==0)return;hanoi(n-1,from,aux,to,count);++*count;hanoi(n-1,aux,to,from,count);}
int main(void){int actual=0;hanoi(4,'A','C','B',&actual);printf("c8927 hanoi=%d,%d\n",actual,hanoi_moves(4));return !(actual==15&&hanoi_moves(4)==15);}
