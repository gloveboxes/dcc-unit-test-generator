#include <stdbool.h>
#include <stdio.h>
static bool valid(int a,int b){return a>=0&&b>=0&&a+b==10;}
int main(void){printf("c9914 predicate=%d/%d\n",valid(3,7),valid(2,9));return 0;}
