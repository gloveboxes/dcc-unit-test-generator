#include <stdarg.h>
#include <stdio.h>
static int product(int n,...){va_list ap;int i,result=1;va_start(ap,n);for(i=0;i<n;++i)result*=va_arg(ap,int);va_end(ap);return result;}
int main(void){printf("c9907 variadic=%d\n",product(4,2,3,4,5));return 0;}
