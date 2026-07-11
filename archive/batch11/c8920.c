#include <stdio.h>
static long prefix_sq_sum(int n){long total=0L;int i;for(i=1;i<=n;++i)total+=(long)i*i;return total;}
int main(void){long a=prefix_sq_sum(10),b=prefix_sq_sum(5);printf("c8920 sqsum=%ld,%ld\n",a,b);return !(a==385L&&b==55L);}
