#include <stdio.h>
static int roman_value(char c){if(c=='I')return 1;if(c=='V')return 5;if(c=='X')return 10;if(c=='L')return 50;if(c=='C')return 100;return 0;}
static int roman(const char *s){int total=0,i,current,next;for(i=0;s[i];++i){current=roman_value(s[i]);next=roman_value(s[i+1]);total+=current<next?-current:current;}return total;}
int main(void){printf("c8913 roman=%d,%d\n",roman("MXL"),roman("CDXLIV"));return 0;}
