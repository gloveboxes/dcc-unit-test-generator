#include <stdio.h>

static int gcd(int a, int b)
{
    int r;
    while (b != 0) { r = a % b; a = b; b = r; }
    return a < 0 ? -a : a;
}
int main(void)
{
    int pairs[4][2] = {{84, 30}, {105, 45}, {221, 143}, {48, 18}};
    int i, result = 0;
    for (i = 0; i < 4; ++i) result += gcd(pairs[i][0], pairs[i][1]);
    printf("c8902 gcdsum=%d\n", result);
    return 0;
}
