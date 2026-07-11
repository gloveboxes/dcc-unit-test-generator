#include <stdio.h>
static int is_upper(char c){return c>='A'&&c<='Z';}
static int has_upper(const char* s){while(*s)if(is_upper(*s++))return 1;return 0;}
int main(void){printf("c8919 upper=%d,%d\n",has_upper("hello"),has_upper("World"));return 0;}
