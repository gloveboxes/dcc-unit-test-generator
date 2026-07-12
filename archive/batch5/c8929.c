#include <stdio.h>
static unsigned long hash(const char *s){unsigned long h=5381UL;int i;for(i=0;s[i];++i)h=(h<<5)+h+(unsigned char)s[i];return h;}
int main(void){printf("c8929 hash=%lu,%lu\n",hash("CPM"),hash("Z80"));return 0;}
