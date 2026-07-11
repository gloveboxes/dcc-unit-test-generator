#include <stdio.h>
#include <stdarg.h>
static int total(int n,...){va_list ap;int i,r=0;va_start(ap,n);for(i=0;i<n;++i)r+=va_arg(ap,int);va_end(ap);return r;}
int main(void){printf("c9907 variadic=%d\n",total(4,2,4,6,8));return 0;}
