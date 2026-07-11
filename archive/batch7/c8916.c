#include <stdio.h>
static int starts_with(const char* s,const char* pre){while(*pre){if(*s++!=*pre++)return 0;}return 1;}
int main(void){printf("c8916 starts=%d,%d\n",starts_with("hello","he"),starts_with("hello","hi"));return 0;}
