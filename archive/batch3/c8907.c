#include <stdio.h>
static int absval(int n){return n<0?-n:n;}
int main(void){int x0,y0,x1,y1,dx,dy,sx,sy,err,e2,count; x0=1;y0=1;x1=7;y1=4;dx=absval(x1-x0);dy=-absval(y1-y0);sx=x0<x1?1:-1;sy=y0<y1?1:-1;err=dx+dy;count=0;for(;;){++count;if(x0==x1&&y0==y1)break;e2=2*err;if(e2>=dy){err+=dy;x0+=sx;}if(e2<=dx){err+=dx;y0+=sy;}}printf("c8907 line=%d/%d,%d\n",count,x0,y0);return 0;}
