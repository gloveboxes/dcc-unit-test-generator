#include <stdio.h>

#define P 3
#define R 3
static int safe(const int available[R],const int allocation[P][R],const int maximum[P][R],int order[P])
{
    int work[R],done[P]={0,0,0},i,j,k,possible,count;for(j=0;j<R;++j)work[j]=available[j];count=0;
    while(count<P){possible=0;for(i=0;i<P;++i)if(!done[i]){possible=1;for(j=0;j<R;++j)if(maximum[i][j]-allocation[i][j]>work[j])possible=0;if(possible){for(k=0;k<R;++k)work[k]+=allocation[i][k];done[i]=1;order[count++]=i;break;}}if(!possible)return 0;}return 1;
}

int main(void)
{
    int available[R]={1,1,2};int allocation[P][R]={{1,0,1},{1,1,0},{0,0,2}};int maximum[P][R]={{2,1,1},{2,2,1},{1,1,3}};int order[P],ok;ok=safe(available,allocation,maximum,order);
    printf("c8934 banker=%d,%d%d%d\n",ok,order[0],order[1],order[2]);
    return !(ok&&order[0]==0&&order[1]==1&&order[2]==2);
}
