#include <stdio.h>
static int trimmed_mean(int count,const int values[count]){int low=values[0],high=values[0],sum=0;for(int i=0;i<count;++i){if(values[i]<low)low=values[i];if(values[i]>high)high=values[i];sum+=values[i];}return (sum-low-high)/(count-2);}
int main(void){int readings[7]={10,12,11,50,9,13,10};int mean=trimmed_mean(7,readings);printf("c9903 trimmed=%d\n",mean);return mean!=11;}
