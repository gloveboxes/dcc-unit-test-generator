#include <stdio.h>
int main(void){int a[4][4]={{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}},r,c,sum=0;for(r=0;r<4;++r)for(c=0;c<4;++c)if(r==c||r+c==3)sum+=a[r][c];printf("c8913 diagonals=%d\n",sum);return 0;}
