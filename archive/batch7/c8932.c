#include <stdio.h>
static void to_lower(char* s){while(*s){if(*s>='A'&&*s<='Z')*s+=32;++s;}}
int main(void){char b[]="DOG456";to_lower(b);printf("c8932 down=%s\n",b);return 0;}
