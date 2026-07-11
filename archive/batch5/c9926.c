#include <stdio.h>
static int replace(int n,char a[n],char from,char to){int i,r=0;for(i=0;i<n;++i)if(a[i]==from){a[i]=to;++r;}return r;}
int main(void){char s[8]="banana";int changed;changed=replace(6,s,'a','o');printf("c9926 replace=%d/%s\n",changed,s);return 0;}
