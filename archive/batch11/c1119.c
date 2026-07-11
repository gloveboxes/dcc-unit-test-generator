#include <stdio.h>
#include <stdint.h>
struct Point3D {
    union {
        struct { int x, y, z; };
        int coord[3];
    };
};
static int manhattan3(const struct Point3D *a, const struct Point3D *b) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int d = a->coord[i] - b->coord[i];
        sum += d < 0 ? -d : d;
    }
    return sum;
}
int main(void) {
    struct Point3D p = {.x=1, .y=-2, .z=3};
    struct Point3D q = {.coord={4, 5, -1}};
    int d = manhattan3(&p, &q);
    printf("c1119 manh3=%d\n", d);
    return d != 14;
}
