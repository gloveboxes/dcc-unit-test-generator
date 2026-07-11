#include <stdio.h>
static void mask_array(int n,int a[n],int mask){int i;for(i=0;i<n;++i)a[i]&=mask;}
int main(void){int a[3]={0xff,0xff,0xff};mask_array(3,a,0x0f);printf("c9911 mask=%x,%x\n",a[0],a[2]);return 0;}
