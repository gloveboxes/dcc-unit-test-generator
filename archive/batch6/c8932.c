#include <stdio.h>
static int first_diff(const char *a,const char *b){int i=0;while(a[i]&&a[i]==b[i])++i;return i;}
int main(void){printf("c8932 diff=%d,%d\n",first_diff("CPM","CPM"),first_diff("CPM","CPU"));return 0;}
