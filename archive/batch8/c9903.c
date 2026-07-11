#include <stdio.h>
struct Vector { int x, y; };
static int dot(struct Vector a, struct Vector b) { return a.x * b.x + a.y * b.y; }
int main(void) {
    int actual = dot((struct Vector){3, 4}, (struct Vector){5, -2});
    printf("c9903 vector=%d\n", actual); return actual != 7;
}
