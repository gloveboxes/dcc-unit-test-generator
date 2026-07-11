#include <stdio.h>
static unsigned hash(const char *s){unsigned h;int i;h=5381;for(i=0;s[i]!='\0';++i)h=((h<<5)+h)+(unsigned char)s[i];return h;}
int main(void){printf("c8917 hash=%u,%u\n",hash("alpha"),hash("beta"));return 0;}
