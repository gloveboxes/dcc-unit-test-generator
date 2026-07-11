#include <stdio.h>
#include <stdint.h>
struct Quaternion {
    union {
        struct { int w, x, y, z; };
        int v[4];
    };
};
static int q_magnitude_sq(const struct Quaternion *q) {
    int s = 0;
    for (int i = 0; i < 4; i++) s += q->v[i] * q->v[i];
    return s;
}
int main(void) {
    struct Quaternion q = {.w=0,.x=1,.y=2,.z=2};
    int m = q_magnitude_sq(&q);
    printf("c1130 quat=%d,%d\n", m, q.z);
    return !(m == 9 && q.z == 2);
}
