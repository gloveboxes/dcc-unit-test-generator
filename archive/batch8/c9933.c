#include <stdio.h>
static int diagonal_sum(int size,const int values[size][3]){int total=0;for(int i=0;i<size&&i<3;++i)total+=values[i][i];return total;}
int main(void){int values[3][3]={{2,0,0},{0,4,0},{0,0,8}};int actual=diagonal_sum(3,values);printf("c9933 diagonal=%d\n",actual);return actual!=14;}
