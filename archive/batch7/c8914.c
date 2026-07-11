#include <stdio.h>
static int find_char(const char* s,char c){int i=0;while(s[i]){if(s[i]==c)return i;++i;}return -1;}
int main(void){printf("c8914 find=%d,%d\n",find_char("hello",'e'),find_char("world",'z'));return 0;}
