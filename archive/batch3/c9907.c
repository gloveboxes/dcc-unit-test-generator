#include <stdio.h>
#include <stdarg.h>
static int sum(int count,...){va_list ap;int i,total;total=0;va_start(ap,count);for(i=0;i<count;++i)total+=va_arg(ap,int);va_end(ap);return total;}
int main(void){printf("c9907 varsum=%d,%d\n",sum(4,2,4,6,8),sum(3,-1,5,9));return 0;}
