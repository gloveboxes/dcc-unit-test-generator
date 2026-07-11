#include <stdio.h>
static int roman(char c){if(c=='I')return 1;if(c=='V')return 5;if(c=='X')return 10;if(c=='L')return 50;if(c=='C')return 100;return 0;}
static int value(const char *s){int i,total,cur,next;total=0;for(i=0;s[i]!='\0';++i){cur=roman(s[i]);next=roman(s[i+1]);if(cur<next)total-=cur;else total+=cur;}return total;}
int main(void){printf("c8901 roman=%d,%d,%d\n",value("MCM"),value("XLII"),value("MMXXIV"));return 0;}
