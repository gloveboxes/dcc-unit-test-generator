#include <stdio.h>

int main(void)
{
    int a[3][3] = {{2,1,3},{0,4,5},{1,2,6}}, det;
    det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    printf("c8915 determinant=%d\n", det);
    return 0;
}
