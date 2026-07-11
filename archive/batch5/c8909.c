#include <stdio.h>
static int count(const char *s,char target){int i,r=0;for(i=0;s[i];++i)if(s[i]==target)++r;return r;}
int main(void){printf("c8909 count=%d,%d\n",count("CPM Z80",' '),count("mississippi",'s'));return 0;}
