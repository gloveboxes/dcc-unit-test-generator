#include <stdio.h>
static void rot13(char* s){while(*s){char c=*s;if(c>='a'&&c<='z')*s=c<'n'?c+13:c-13;else if(c>='A'&&c<='Z')*s=c<'N'?c+13:c-13;++s;}}
int main(void){char b[]="Hello";rot13(b);printf("c8926 rot=%s\n",b);return 0;}
