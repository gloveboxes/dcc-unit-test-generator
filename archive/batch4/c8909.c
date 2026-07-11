#include <stdio.h>
static int isqrt(int n){int root=0;while((root+1)*(root+1)<=n)++root;return root;}
int main(void){printf("c8909 isqrt=%d,%d,%d\n",isqrt(0),isqrt(15),isqrt(81));return 0;}
