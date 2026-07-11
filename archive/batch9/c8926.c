#include <stdio.h>
struct Debounce{int stable;int candidate;int count;};
static int update(struct Debounce *d,int sample,int threshold){if(sample==d->candidate)++d->count;else{d->candidate=sample;d->count=1;}if(d->count>=threshold)d->stable=d->candidate;return d->stable;}
int main(void){struct Debounce d={0,0,0};int samples[6]={1,0,1,1,1,0},i,out=0;for(i=0;i<6;++i)out=update(&d,samples[i],3);printf("c8926 debounce=%d,%d\n",out,d.count);return !(out==1&&d.count==1);}
