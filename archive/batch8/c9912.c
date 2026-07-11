#include <stdio.h>
struct Rect { int x, y, width, height; };
static int area(struct Rect r) { return r.width * r.height; }
int main(void) {
    struct Rect r = (struct Rect){.x=4, .y=3, .width=8, .height=5}; int actual = area(r);
    printf("c9912 rect=%d,%d,%d\n", r.x, r.y, actual); return !(r.x == 4 && r.y == 3 && actual == 40);
}
