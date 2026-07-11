#include <stdio.h>

struct Point { int x; int y; };
static int cross(struct Point a, struct Point b, struct Point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
static int hull(struct Point *p, int n, struct Point *out)
{
    int i, k, t; struct Point swap;
    for (i=0;i<n-1;++i) for (t=i+1;t<n;++t) if (p[t].x<p[i].x || (p[t].x==p[i].x && p[t].y<p[i].y)) { swap=p[i];p[i]=p[t];p[t]=swap; }
    k=0; for(i=0;i<n;++i){while(k>=2&&cross(out[k-2],out[k-1],p[i])<=0)--k;out[k++]=p[i];}
    t=k+1; for(i=n-2;i>=0;--i){while(k>=t&&cross(out[k-2],out[k-1],p[i])<=0)--k;out[k++]=p[i];}
    return k-1;
}

int main(void)
{
    struct Point p[7]={{0,0},{2,1},{4,0},{3,3},{1,4},{2,2},{1,1}}, out[8]; int n, area, i, j;
    n=hull(p,7,out); area=0; for(i=0;i<n;++i){j=(i+1)%n;area+=out[i].x*out[j].y-out[i].y*out[j].x;}
    printf("c8916 hull=%d,%d\n",n,area);
    return !(n==4&&area==21);
}
