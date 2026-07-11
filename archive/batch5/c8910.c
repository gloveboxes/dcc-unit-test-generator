#include <stdio.h>
static int pal(const char *s,int n){int i;for(i=0;i<n/2;++i)if(s[i]!=s[n-1-i])return 0;return 1;}
int main(void){printf("c8910 pal=%d,%d\n",pal("RADAR",5),pal("CPM",3));return 0;}
