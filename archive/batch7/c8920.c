#include <stdio.h>
static int string_len(const char* s){int r=0;while(*s++){++r;}return r;}
int main(void){printf("c8920 len=%d,%d\n",string_len("abc"),string_len(""));return 0;}
