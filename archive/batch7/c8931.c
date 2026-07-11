#include <stdio.h>
static void to_upper(char* s){while(*s){if(*s>='a'&&*s<='z')*s-=32;++s;}}
int main(void){char b[]="cat123";to_upper(b);printf("c8931 up=%s\n",b);return 0;}
