#include <stdio.h>

struct Queue { int weight; int credit; int jobs; };

static int dispatch(struct Queue *q, int n)
{
    int i, best;
    best = 0;
    for (i = 0; i < n; ++i) {
        q[i].credit += q[i].weight;
        if (q[i].credit > q[best].credit) best = i;
    }
    q[best].credit -= 10;
    ++q[best].jobs;
    return best;
}

int main(void)
{
    struct Queue q[3] = {{5,0,0},{3,0,0},{2,0,0}};
    int i, code;
    code = 0;
    for (i = 0; i < 10; ++i) code = code * 3 + dispatch(q, 3);
    printf("c8902 scheduler=%d,%d,%d,%d\n", q[0].jobs, q[1].jobs, q[2].jobs, code);
    return !(q[0].jobs == 5 && q[1].jobs == 3 && q[2].jobs == 2 && code == 11037);
}
