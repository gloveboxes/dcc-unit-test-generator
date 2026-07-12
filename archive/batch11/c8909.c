#include <stdio.h>
static unsigned long fnv1a(const unsigned char *data,int n){unsigned long h=2166136261UL;int i;for(i=0;i<n;++i){h^=data[i];h=(h*16777619UL)&0xffffffffUL;}return h;}
int main(void){static const unsigned char a[]="dcc",b[]="Z80";unsigned long ha=fnv1a(a,3),hb=fnv1a(b,3);printf("c8909 fnv=%lu,%d\n",ha%10000UL,ha!=hb);return ha==hb;}
