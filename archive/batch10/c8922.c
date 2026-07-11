#include <stdio.h>

static int stuff(const unsigned char *in,int n,unsigned char marker,unsigned char *out,int cap)
{
    int i,k;k=0;
    for(i=0;i<n;++i){if(in[i]==marker){if(k+2>cap)return -1;out[k++]=marker;out[k++]=0;}else{if(k>=cap)return -1;out[k++]=in[i];}}
    return k;
}
static int unstuff(const unsigned char *in,int n,unsigned char marker,unsigned char *out)
{
    int i,k;k=0;for(i=0;i<n;++i){out[k++]=in[i];if(in[i]==marker){if(i+1>=n||in[++i]!=0)return -1;}}return k;
}

int main(void)
{
    unsigned char input[6]={7,255,8,9,255,10},wire[10],back[6];int wn,bn,ok,i;wn=stuff(input,6,255U,wire,10);bn=unstuff(wire,wn,255U,back);ok=bn==6;for(i=0;i<6&&ok;++i)ok=back[i]==input[i];
    printf("c8922 stuffing=%d,%d,%d\n",wn,bn,ok);
    return !(wn==8&&bn==6&&ok);
}
