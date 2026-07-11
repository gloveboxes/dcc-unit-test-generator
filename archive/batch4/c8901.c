#include <stdio.h>
static int parse(const char *s,int *out){int sign=1,value=0,i=0;if(s[0]=='-'){sign=-1;i=1;}if(s[i]=='\0')return 0;for(;s[i]!='\0';++i){if(s[i]<'0'||s[i]>'9')return 0;value=value*10+s[i]-'0';}*out=sign*value;return 1;}
int main(void){int a,b,ok1,ok2;ok1=parse("-2048",&a);ok2=parse("12x",&b);printf("c8901 parse=%d/%d,%d\n",ok1,a,ok2);return 0;}
