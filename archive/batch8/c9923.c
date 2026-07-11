#include <stdio.h>
static int stable_partition(int count,const int input[count],int output[count]) { int used=0; for(int i=0;i<count;++i)if(input[i]>=0)output[used++]=input[i]; for(int i=0;i<count;++i)if(input[i]<0)output[used++]=input[i]; return used; }
int main(void) { int input[5]={-1,4,-2,7,3},output[5]; stable_partition(5,input,output); printf("c9923 partition=%d,%d\n",output[0],output[4]); return !(output[0]==4 && output[4]==-2); }
