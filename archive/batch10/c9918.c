#include <stdio.h>
#include <stdarg.h>

static long weighted(int count,...){va_list ap;long total=0L;va_start(ap,count);for(int i=0;i<count;++i){long value=va_arg(ap,long);long weight=va_arg(ap,long);total+=value*weight;}va_end(ap);return total;}
int main(void){long a=weighted(3,12L,2L,-5L,3L,8L,4L),b=weighted(2,100L,1L,25L,-2L);printf("c9918 weighted=%ld,%ld\n",a,b);return !(a==41L&&b==50L);}
