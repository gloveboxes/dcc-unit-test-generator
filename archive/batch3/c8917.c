#include <stdio.h>
static unsigned long hash(const char *s){unsigned long h;int i;h=5381UL;for(i=0;s[i]!='\0';++i)h=(((h<<5)+h)+(unsigned char)s[i])&0xffffffffUL;return h;}
int main(void){printf("c8917 hash=%lu,%lu\n",hash("alpha"),hash("beta"));return 0;}
