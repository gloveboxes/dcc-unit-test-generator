#include <stdio.h>
#include <stdint.h>
enum Dir { NORTH=0, EAST=1, SOUTH=2, WEST=3 };
static const int dx[4] = { [NORTH]=0, [EAST]=1, [SOUTH]=0, [WEST]=-1 };
static const int dy[4] = { [NORTH]=1, [EAST]=0, [SOUTH]=-1, [WEST]=0 };
int main(void) {
    int x = 0, y = 0;
    int moves[4] = {3, 2, 3, 2};
    for (int d = 0; d < 4; d++)
        for (int s = 0; s < moves[d]; s++) { x += dx[d]; y += dy[d]; }
    printf("c9901 pos=%d,%d\n", x, y);
    return !(x == 0 && y == 0);
}
