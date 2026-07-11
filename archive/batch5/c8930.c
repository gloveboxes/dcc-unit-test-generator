#include <stdio.h>
static int line(int x0,int y0,int x1,int y1){int dx=x1-x0,dy=y1-y0,err=dx-dy,count=0,e2;for(;;){++count;if(x0==x1&&y0==y1)return count;e2=2*err;if(e2>-dy){err-=dy;++x0;}if(e2<dx){err+=dx;++y0;}}}
int main(void){printf("c8930 line=%d\n",line(1,1,7,4));return 0;}
