#include <stdio.h>
static inline int clamp(int value,int low,int high){if(value<low)return low;if(value>high)return high;return value;}
int main(void){printf("c9906 clamp=%d,%d,%d\n",clamp(-4,0,9),clamp(4,0,9),clamp(14,0,9));return 0;}
