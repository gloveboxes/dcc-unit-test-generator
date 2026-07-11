#include <stdio.h>
static unsigned hash(const char *s){unsigned h=5381;int i;for(i=0;s[i];++i)h=(h<<5)+h+(unsigned char)s[i];return h;}
int main(void){printf("c8929 hash=%u,%u\n",hash("CPM"),hash("Z80"));return 0;}
