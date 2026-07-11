#include <stdio.h>
static unsigned char lrc(const unsigned char *data,int count){unsigned int sum=0;int i;for(i=0;i<count;++i)sum+=data[i];return (unsigned char)(0U-sum);}
int main(void){static const unsigned char data[]={1,2,3,4,5};unsigned char check=lrc(data,5);printf("c8907 lrc=%u\n",(unsigned)check);return (unsigned char)(check+15U)!=0;}
