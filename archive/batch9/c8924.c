#include <stdio.h>
static long evaluate(const int coefficients[],int count,int x){long value=0L;int i;for(i=count-1;i>=0;--i)value=value*x+coefficients[i];return value;}
int main(void){int c[4]={5,-2,0,3};long actual=evaluate(c,4,4);printf("c8924 poly=%ld\n",actual);return actual!=189L;}
