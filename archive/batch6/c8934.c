#include <stdio.h>
static int run_length(const char *s,char target){int i=0,r=0;while(s[i]==target){++r;++i;}return r;}
int main(void){printf("c8934 run=%d,%d\n",run_length("aaab",'a'),run_length("bbba",'b'));return 0;}
