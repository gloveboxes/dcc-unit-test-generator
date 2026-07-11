#include <stdio.h>
static int count_vowels(const char* s){int r=0;while(*s){char c=*s++;if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')++r;}return r;}
int main(void){printf("c8918 vow=%d,%d\n",count_vowels("hello"),count_vowels("xyz"));return 0;}
