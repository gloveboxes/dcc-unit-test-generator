#include <stdio.h>

static int line_points(int x0, int y0, int x1, int y1)
{
    int dx = x1 > x0 ? x1 - x0 : x0 - x1;
    int dy = y1 > y0 ? y1 - y0 : y0 - y1;
    int sx = x0 < x1 ? 1 : -1; int sy = y0 < y1 ? 1 : -1;
    int error = dx - dy; int twice; int count = 0;
    while (1) {
        ++count; if (x0 == x1 && y0 == y1) break;
        twice = error * 2;
        if (twice > -dy) { error -= dy; x0 += sx; }
        if (twice < dx) { error += dx; y0 += sy; }
    }
    return count;
}

int main(void)
{
    int count = line_points(1, 2, 7, 5);
    printf("c8925 line=%d\n", count);
    return count != 7;
}
