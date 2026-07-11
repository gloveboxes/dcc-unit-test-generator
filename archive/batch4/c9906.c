#include <stdio.h>
static inline int min_int(int a,int b){return a<b?a:b;}
static inline int max_int(int a,int b){return a>b?a:b;}
int main(void){printf("c9906 bounds=%d,%d\n",min_int(7,3),max_int(7,3));return 0;}
