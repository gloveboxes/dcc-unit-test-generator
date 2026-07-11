#include <stdio.h>

struct Point { int x; int y; };
static int contains(const struct Point *p, int n, struct Point q)
{
    int i, j, inside, hit;
    inside=0; j=n-1;
    for(i=0;i<n;j=i++){
        hit=((p[i].y>q.y)!=(p[j].y>q.y)) && q.x < p[i].x+(long)(p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y);
        if(hit) inside=!inside;
    }
    return inside;
}

int main(void)
{
    struct Point polygon[5]={{0,0},{6,0},{6,5},{3,2},{0,5}}, a={1,1}, b={3,4}; int in1,in2;
    in1=contains(polygon,5,a); in2=contains(polygon,5,b);
    printf("c8917 polygon=%d,%d\n",in1,in2);
    return !(in1==1&&in2==0);
}
