#include <stdio.h>

struct Cell { int row; int col; int value; };

static int transpose(const struct Cell *in, int n, struct Cell *out)
{
    int col, i, k;
    k = 0;
    for (col = 0; col < 4; ++col) for (i = 0; i < n; ++i) if (in[i].col == col) {
        out[k].row = in[i].col; out[k].col = in[i].row; out[k].value = in[i].value; ++k;
    }
    return k;
}

int main(void)
{
    struct Cell in[5] = {{0,2,8},{1,0,3},{1,3,5},{2,1,7},{2,3,4}}, out[5];
    int n, signature, i;
    n = transpose(in,5,out); signature = 0;
    for (i = 0; i < n; ++i) signature += (out[i].row + 1) * (out[i].col + 2) * out[i].value;
    printf("c8912 sparse=%d,%d,%d\n", n, signature, out[0].value);
    return !(n == 5 && signature == 237 && out[0].value == 3);
}
