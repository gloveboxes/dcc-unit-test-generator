#include <stdio.h>
#define MAXN 8
static int edit(const char *a,int na,const char *b,int nb){int dp[MAXN+1][MAXN+1];int i,j;for(i=0;i<=na;++i)dp[i][0]=i;for(j=0;j<=nb;++j)dp[0][j]=j;for(i=1;i<=na;++i)for(j=1;j<=nb;++j){int cost=a[i-1]!=b[j-1];int sub=dp[i-1][j-1]+cost,del=dp[i-1][j]+1,ins=dp[i][j-1]+1;dp[i][j]=sub<del?(sub<ins?sub:ins):(del<ins?del:ins);}return dp[na][nb];}
int main(void){int d=edit("kitten",6,"sitting",7);printf("c8903 edit=%d\n",d);return d!=3;}
