#include <stdio.h>
struct AABB {
    union { struct { int x, y; }; int min[2]; };
    union { struct { int w, h; }; int size[2]; };
};
static int intersects(const struct AABB *a, const struct AABB *b) {
    return a->x < b->x + b->w && a->x + a->w > b->x &&
           a->y < b->y + b->h && a->y + a->h > b->y;
}
int main(void) {
    struct AABB box1 = {.x=0,.y=0,.w=10,.h=10};
    struct AABB box2 = {.x=5,.y=5,.w=10,.h=10};
    struct AABB box3 = {.x=20,.y=0,.w=5,.h=5};
    int a = intersects(&box1, &box2);
    int b = intersects(&box1, &box3);
    printf("c1106 aabb=%d,%d\n", a, b);
    return !(a && !b);
}
