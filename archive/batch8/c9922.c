#include <stdio.h>
#include <stdarg.h>
static long weighted_sum(int count, ...) { va_list ap; long total=0L,value; va_start(ap,count); for(int i=1;i<=count;++i){value=va_arg(ap,long);total+=value*i;} va_end(ap); return total; }
int main(void) { long actual=weighted_sum(3,10L,20L,30L); printf("c9922 weighted=%ld\n",actual); return actual!=140L; }
