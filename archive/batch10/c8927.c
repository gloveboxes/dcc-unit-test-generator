#include <stdio.h>

static void sort3(int *a,int *b,int *c){int t;if(*a>*b){t=*a;*a=*b;*b=t;}if(*b>*c){t=*b;*b=*c;*c=t;}if(*a>*b){t=*a;*a=*b;*b=t;}}
static int median_filter(const int *in,int n,int *out)
{
    int i,a,b,c,sum;sum=0;for(i=1;i<n-1;++i){a=in[i-1];b=in[i];c=in[i+1];sort3(&a,&b,&c);out[i-1]=b;sum+=b;}return sum;
}

int main(void)
{
    int input[8]={10,11,90,12,13,-20,14,15},out[6];int sum;sum=median_filter(input,8,out);
    printf("c8927 medianfilter=%d,%d,%d\n",sum,out[1],out[4]);
    return !(sum==75&&out[1]==12&&out[4]==13);
}
