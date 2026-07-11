#include <stdio.h>
static int encoded(const char *s){int i,count,total;total=0;for(i=0;s[i]!='\0';){count=1;while(s[i]==s[i+1]){++count;++i;}total+=count;++i;}return total;}
int main(void){printf("c8914 rle=%d,%d\n",encoded("AAABBC"),encoded("XYZZZZ"));return 0;}
