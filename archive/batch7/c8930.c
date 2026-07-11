#include <stdio.h>
static void trim_right(char* s){int e=0;while(s[e])++e;while(e>0&&s[e-1]==' ')--e;s[e]=0;}
int main(void){char b[]="dog  ";trim_right(b);printf("c8930 rtrim=%s.\n",b);return 0;}
