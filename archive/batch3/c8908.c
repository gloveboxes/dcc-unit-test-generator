#include <stdio.h>
#include <string.h>
static int distance(const char *a,const char *b){int d[8][8];int i,j,cost,del,ins,sub;for(i=0;i<=6;++i)d[i][0]=i;for(j=0;j<=6;++j)d[0][j]=j;for(i=1;i<=6;++i)for(j=1;j<=6;++j){cost=a[i-1]==b[j-1]?0:1;del=d[i-1][j]+1;ins=d[i][j-1]+1;sub=d[i-1][j-1]+cost;d[i][j]=del<ins?del:ins;if(sub<d[i][j])d[i][j]=sub;}return d[6][6];}
int main(void){printf("c8908 edit=%d\n",distance("kitten","sitten"));return 0;}
