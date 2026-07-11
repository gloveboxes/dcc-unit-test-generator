#include <stdio.h>
struct Interval{int lo,hi;};
static int overlaps(const struct Interval *a,const struct Interval *b){return a->hi>=b->lo&&b->hi>=a->lo;}
static int any_overlap(const struct Interval a[],int n){int i,j;for(i=0;i<n-1;++i)for(j=i+1;j<n;++j)if(overlaps(&a[i],&a[j]))return 1;return 0;}
int main(void){struct Interval disjoint[4]={{1,3},{5,7},{9,11},{13,15}};struct Interval overlap[3]={{1,5},{4,8},{10,12}};int a=any_overlap(disjoint,4),b=any_overlap(overlap,3);printf("c8925 ivals=%d,%d\n",a,b);return !(!a&&b);}
