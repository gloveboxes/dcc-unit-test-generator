#include <stdio.h>
#include <stdint.h>
struct Span {
    union {
        struct { uint16_t start; uint16_t length; };
        uint32_t packed;
    };
};
static int span_end(const struct Span *s) { return s->start + s->length; }
static int span_overlaps(const struct Span *a, const struct Span *b) {
    return (int)a->start < span_end(b) && (int)b->start < span_end(a);
}
int main(void) {
    struct Span s1 = {.start=10, .length=20};
    struct Span s2 = {.start=25, .length=10};
    struct Span s3 = {.start=40, .length=5};
    int a = span_overlaps(&s1, &s2);
    int b = span_overlaps(&s1, &s3);
    printf("c1121 span=%d,%d\n", a, b);
    return !(a && !b);
}
