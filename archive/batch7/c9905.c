#include <stdio.h>
#include <stdarg.h>
static int sum_n(int n,...){va_list ap;int i,r=0;va_start(ap,n);for(i=0;i<n;++i)r+=va_arg(ap,int);va_end(ap);return r;}
int main(void){printf("c9905 var=%d\n",sum_n(3,10,20,30));return 0;}
