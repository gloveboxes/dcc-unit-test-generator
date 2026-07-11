#include <stdio.h>
#include <stdbool.h>

static bool deployable(int n,const bool deps[n][n],const bool ready[n]){for(int service=0;service<n;++service)if(ready[service])for(int dependency=0;dependency<n;++dependency)if(deps[service][dependency]&&!ready[dependency])return false;return true;}
int main(void){bool deps[4][4]={{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,1,0}},good[4]={1,1,1,0},bad[4]={1,0,1,0};bool a=deployable(4,deps,good),b=deployable(4,deps,bad);printf("c9913 deploy=%d,%d\n",(int)a,(int)b);return !(a&&!b);}
