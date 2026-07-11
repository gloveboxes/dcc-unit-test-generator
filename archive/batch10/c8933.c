#include <stdio.h>

struct Record { int key; int generation; int value; int live; };
static int compact(const struct Record *log,int n,struct Record *out)
{
    int i,j,count,found;count=0;
    for(i=n-1;i>=0;--i){found=0;for(j=0;j<count;++j)if(out[j].key==log[i].key)found=1;if(!found){out[count]=log[i];++count;}}
    for(i=0;i<count/2;++i){struct Record t;t=out[i];out[i]=out[count-1-i];out[count-1-i]=t;}return count;
}

int main(void)
{
    struct Record log[6]={{1,1,10,1},{2,1,20,1},{1,2,15,1},{3,1,30,1},{2,2,0,0},{3,2,35,1}},out[4];int n,sum,i; n=compact(log,6,out);sum=0;for(i=0;i<n;++i)if(out[i].live)sum+=out[i].value;
    printf("c8933 compaction=%d,%d,%d\n",n,sum,out[1].live);
    return !(n==3&&sum==50&&out[1].live==0);
}
