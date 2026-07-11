#include <stdio.h>
typedef int (*Handler)(int);
static int double_it(int value){return value*2;}
static int negate(int value){return -value;}
static int square(int value){return value*value;}
enum Command { DOUBLE, NEGATE, SQUARE };
static const Handler handlers[3]={[SQUARE]=square,[DOUBLE]=double_it,[NEGATE]=negate};
int main(void){int value=handlers[SQUARE](handlers[NEGATE](3));printf("c9928 dispatch=%d\n",value);return value!=9;}
