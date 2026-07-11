#include <stdio.h>

struct Item { int on_hand; int daily; int lead; int reserve; };
static int order(const struct Item *p,int target_days)
{
    int reorder,target;if(p->on_hand>p->daily*p->lead+p->reserve)return 0;reorder=p->daily*p->lead+p->reserve;target=p->daily*target_days+p->reserve;return target>p->on_hand?target-p->on_hand:reorder-p->on_hand;
}

int main(void)
{
    struct Item stock[3]={{18,4,3,5},{40,3,5,6},{7,2,2,4}};int i,total,lines;total=0;lines=0;
    for(i=0;i<3;++i){int amount;amount=order(&stock[i],10);if(amount){total+=amount;++lines;}}
    printf("c8925 inventory=%d,%d\n",lines,total);
    return !(lines==1&&total==17);
}
