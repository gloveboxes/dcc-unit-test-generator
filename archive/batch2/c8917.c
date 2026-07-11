#include <stdio.h>
int main(void){int a[4][4]={{1,0,0,1},{0,1,1,0},{1,1,0,0},{0,0,1,1}},r,c,score=0;for(r=0;r<4;++r){for(c=0;c<4;++c)score+=a[r][c]*(r+1)*(c+1);}printf("c8917 weighted=%d\n",score);return 0;}
