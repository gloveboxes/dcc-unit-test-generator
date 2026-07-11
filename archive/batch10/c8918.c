#include <stdio.h>

static int code(int x,int y){return (x<0?1:0)|(x>10?2:0)|(y<0?4:0)|(y>8?8:0);}
static int clip(int *x0,int *y0,int *x1,int *y1)
{
    int a,b,c,x,y;
    for(;;){a=code(*x0,*y0);b=code(*x1,*y1);if(!(a|b))return 1;if(a&b)return 0;c=a?a:b;
        if(c&8){x=*x0+(*x1-*x0)*(8-*y0)/(*y1-*y0);y=8;}
        else if(c&4){x=*x0+(*x1-*x0)*(0-*y0)/(*y1-*y0);y=0;}
        else if(c&2){y=*y0+(*y1-*y0)*(10-*x0)/(*x1-*x0);x=10;}
        else{y=*y0+(*y1-*y0)*(0-*x0)/(*x1-*x0);x=0;}
        if(c==a){*x0=x;*y0=y;}else{*x1=x;*y1=y;}
    }
}

int main(void)
{
    int x0,y0,x1,y1,ok;
    x0=-3;y0=2;x1=14;y1=7;ok=clip(&x0,&y0,&x1,&y1);
    printf("c8918 clipping=%d,%d,%d,%d,%d\n",ok,x0,y0,x1,y1);
    return !(ok&&x0==0&&y0==2&&x1==10&&y1==5);
}
