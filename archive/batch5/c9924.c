#include <stdio.h>
static int matrix_trace(const int a[2][2]){return a[0][0]+a[1][1];}
int main(void){int a[2][2]={{3,4},{5,6}};printf("c9924 trace=%d\n",matrix_trace(a));return 0;}
