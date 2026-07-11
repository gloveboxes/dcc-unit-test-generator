#include <stdio.h>
static int edit(const char *a,const char *b){int d[8][8],i,j,x,y,z;for(i=0;i<=6;++i)d[i][0]=i;for(j=0;j<=6;++j)d[0][j]=j;for(i=1;i<=6;++i)for(j=1;j<=6;++j){x=d[i-1][j]+1;y=d[i][j-1]+1;z=d[i-1][j-1]+(a[i-1]!=b[j-1]);d[i][j]=x<y?x:y;if(z<d[i][j])d[i][j]=z;}return d[6][6];}
int main(void){printf("c8924 edit=%d\n",edit("kitten","sitten"));return 0;}
