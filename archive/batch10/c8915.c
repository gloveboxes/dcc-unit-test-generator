#include <stdio.h>

static int circle_points(int radius, int *checksum)
{
    int x, y, error, points;
    x = radius; y = 0; error = 1 - radius; points = 0; *checksum = 0;
    while (x >= y) {
        points += x == y || y == 0 ? 4 : 8;
        *checksum += x * 11 + y * 7;
        ++y;
        if (error < 0) error += 2 * y + 1;
        else { --x; error += 2 * (y - x) + 1; }
    }
    return points;
}

int main(void)
{
    int points, checksum;
    points = circle_points(6,&checksum);
    printf("c8915 circle=%d,%d\n", points, checksum);
    return !(points == 32 && checksum == 367);
}
