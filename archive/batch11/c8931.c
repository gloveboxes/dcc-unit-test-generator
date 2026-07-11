#include <stdio.h>
static int rl_stats(const char *s,int *max_run,int *num_runs){int i=0,cur=1;*max_run=0;*num_runs=0;if(!s[0])return 0;while(s[i+1]){if(s[i+1]==s[i])++cur;else{++*num_runs;if(cur>*max_run)*max_run=cur;cur=1;}++i;}++*num_runs;if(cur>*max_run)*max_run=cur;return 1;}
int main(void){int maxrun,numruns;rl_stats("AAABBBBCC",&maxrun,&numruns);printf("c8931 rlstat=%d,%d\n",maxrun,numruns);return !(maxrun==4&&numruns==3);}
