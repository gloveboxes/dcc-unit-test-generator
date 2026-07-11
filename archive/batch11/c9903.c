#include <stdio.h>
#include <stdint.h>
struct Vec2 { int16_t x, y; };
static struct Vec2 add(struct Vec2 a, struct Vec2 b) { return (struct Vec2){.x = (int16_t)(a.x + b.x), .y = (int16_t)(a.y + b.y)}; }
static struct Vec2 scale(struct Vec2 v, int s) { return (struct Vec2){.x = (int16_t)(v.x * s), .y = (int16_t)(v.y * s)}; }
int main(void) {
    struct Vec2 *a = &(struct Vec2){.x = 3, .y = -1};
    struct Vec2 *b = &(struct Vec2){.x = -1, .y = 4};
    struct Vec2 r = add(scale(*a, 2), *b);
    printf("c9903 vec=%d,%d\n", (int)r.x, (int)r.y);
    return !(r.x == 5 && r.y == 2);
}
