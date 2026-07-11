#include <stdio.h>

static int slip(const unsigned char *in,int n,unsigned char *out,int cap)
{
    int i,k;k=0;if(cap<2)return -1;out[k++]=0xC0U;
    for(i=0;i<n;++i){if(in[i]==0xC0U){if(k+2>cap)return -1;out[k++]=0xDBU;out[k++]=0xDCU;}else if(in[i]==0xDBU){if(k+2>cap)return -1;out[k++]=0xDBU;out[k++]=0xDDU;}else{if(k+1>cap)return -1;out[k++]=in[i];}}
    if(k>=cap)return -1;out[k++]=0xC0U;return k;
}

int main(void)
{
    unsigned char in[5]={1,0xC0U,2,0xDBU,3},out[10];int n;unsigned sum;int i;n=slip(in,5,out,10);sum=0;for(i=0;i<n;++i)sum+=out[i];
    printf("c8921 slip=%d,%u,%02x\n",n,sum,(unsigned)out[3]);
    return !(n==9&&sum==1269U&&out[3]==0xDCU);
}
