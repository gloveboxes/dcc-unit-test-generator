#include <stdio.h>
static inline int cube(int n){return n*n*n;}
int main(void){printf("c9906 inline=%d,%d\n",cube(3),cube(-2));return 0;}
