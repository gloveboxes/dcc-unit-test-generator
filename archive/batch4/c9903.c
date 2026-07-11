#include <stdio.h>
#include <stdbool.h>
static bool all_digits(const char *s){int i;if(!s[0])return false;for(i=0;s[i];++i)if(s[i]<'0'||s[i]>'9')return false;return true;}
int main(void){printf("c9903 digits=%d,%d\n",all_digits("2048"),all_digits("20a8"));return 0;}
