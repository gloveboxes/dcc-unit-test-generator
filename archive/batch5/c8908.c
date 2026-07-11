#include <stdio.h>
static void reverse_range(char *s,int n){int i;char t;for(i=0;i<n/2;++i){t=s[i];s[i]=s[n-1-i];s[n-1-i]=t;}}
int main(void){char s[8]="CPMZ80";reverse_range(s,6);printf("c8908 reverse=%s\n",s);return 0;}
