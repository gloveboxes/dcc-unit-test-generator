#include <stdio.h>
int main(void){int n=5,values[n],i,total=0;for(i=0;i<n;++i)values[i]=(i+1)*(i+1);for(i=0;i<n;++i)total+=values[i];printf("c9903 vla=%d size=%d\n",total,(int)sizeof values);return 0;}
