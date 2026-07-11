#include <stdio.h>
#include <stdarg.h>

static long span(int count,...){va_list ap;long low,high,value;va_start(ap,count);low=high=va_arg(ap,long);for(int i=1;i<count;++i){value=va_arg(ap,long);if(value<low)low=value;if(value>high)high=value;}va_end(ap);return high-low;}
int main(void){long a=span(6,14L,-3L,27L,8L,19L,0L),b=span(3,40000L,42000L,39000L);printf("c9919 span=%ld,%ld\n",a,b);return !(a==30L&&b==3000L);}
