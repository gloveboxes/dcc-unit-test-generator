#include <stdio.h>
#include <stdarg.h>
static int weighted_sum(int count,...){va_list ap;int i,total=0,value,weight;va_start(ap,count);for(i=0;i<count;++i){value=va_arg(ap,int);weight=va_arg(ap,int);total+=value*weight;}va_end(ap);return total;}
int main(void){printf("c9907 variadic=%d\n",weighted_sum(3,2,5,3,4,7,1));return 0;}
