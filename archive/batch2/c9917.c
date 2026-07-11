#include <stdio.h>
int main(void){int n=8,table[n],i,total=0;for(i=0;i<n;++i)table[i]=(i*i+3*i+1)%11;for(i=0;i<n;++i)total+=table[i];printf("c9917 vlatable=%d\n",total);return 0;}
