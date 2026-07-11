#include <stdio.h>
static inline int square(int x){return x*x;}
int main(void){printf("c9906 inline=%d,%d\n",square(5),square(-3));return 0;}
