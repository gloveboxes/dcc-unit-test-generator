#include <stdio.h>
#include <stdbool.h>
static bool palindrome(const char *s,int n){int i;for(i=0;i<n/2;++i)if(s[i]!=s[n-1-i])return false;return true;}
int main(void){printf("c9903 palindrome=%d,%d\n",palindrome("level",5),palindrome("world",5));return 0;}
