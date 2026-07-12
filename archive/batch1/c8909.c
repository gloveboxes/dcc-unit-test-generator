#include <stdio.h>

static int edit(const char *a, const char *b)
{
    int d[8][8], i, j, cost, best;
    d[0][0] = 0;
    for (i = 0; a[i] != '\0'; ++i) d[i + 1][0] = i + 1;
    for (j = 0; b[j] != '\0'; ++j) d[0][j + 1] = j + 1;
    for (i = 0; a[i] != '\0'; ++i) for (j = 0; b[j] != '\0'; ++j) {
        cost = a[i] == b[j] ? 0 : 1;
        best = d[i][j + 1] + 1 < d[i + 1][j] + 1 ? d[i][j + 1] + 1 : d[i + 1][j] + 1;
        d[i + 1][j + 1] = best < d[i][j] + cost ? best : d[i][j] + cost;
    }
    return d[i][j];
}
int main(void)
{
    printf("c8909 distance=%d\n", edit("kitten", "sitting"));
    return 0;
}
