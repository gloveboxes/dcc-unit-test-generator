#include <stdio.h>
enum Unit { UNIT_MM, UNIT_CM, UNIT_M, UNIT_COUNT };
static const int scale[UNIT_COUNT] = {[UNIT_M]=1000,[UNIT_MM]=1,[UNIT_CM]=10};
static int convert(int value, enum Unit from, enum Unit to) { return value*scale[from]/scale[to]; }
int main(void) { int actual=convert(250,UNIT_CM,UNIT_M); printf("c9917 units=%d\n",actual); return actual!=2; }
