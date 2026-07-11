#include <stdio.h>

static unsigned hash1(const char *s){unsigned h;h=0;while(*s)h=h*31U+(unsigned char)*s++;return h;}
static unsigned hash2(const char *s){unsigned h;h=7;while(*s)h=h*17U^(unsigned char)*s++;return h;}
static void add(unsigned char *bits,const char *s){unsigned a,b;a=hash1(s)%32U;b=hash2(s)%32U;bits[a/8]|=(unsigned char)(1U<<(a%8));bits[b/8]|=(unsigned char)(1U<<(b%8));}
static int maybe(const unsigned char *bits,const char *s){unsigned a,b;a=hash1(s)%32U;b=hash2(s)%32U;return !!(bits[a/8]&(1U<<(a%8)))&&!!(bits[b/8]&(1U<<(b%8)));}

int main(void)
{
    unsigned char bits[4]={0,0,0,0};int a,b;add(bits,"ALPHA");add(bits,"GAMMA");add(bits,"OMEGA");a=maybe(bits,"GAMMA");b=maybe(bits,"DELTA");
    printf("c8919 bloom=%d,%d,%02x%02x%02x%02x\n",a,b,(unsigned)bits[0],(unsigned)bits[1],(unsigned)bits[2],(unsigned)bits[3]);
    return !(a&&!b);
}
