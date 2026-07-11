#include <stdio.h>
static unsigned int fnv1a(const unsigned char *data,int n){unsigned int h=2166136261U;int i;for(i=0;i<n;++i){h^=data[i];h=(unsigned int)(h*16777619U);}return h;}
int main(void){static const unsigned char a[]="dcc",b[]="Z80";unsigned int ha=fnv1a(a,3),hb=fnv1a(b,3);printf("c8909 fnv=%u,%d\n",ha%10000U,ha!=hb);return ha==hb;}
