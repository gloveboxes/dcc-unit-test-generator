#include <stdio.h>
#include <stdarg.h>
static int product(int n,...){va_list ap;int i,r=1;va_start(ap,n);for(i=0;i<n;++i)r*=va_arg(ap,int);va_end(ap);return r;}
int main(void){printf("c9907 variadic=%d\n",product(4,2,3,4,5));return 0;}
