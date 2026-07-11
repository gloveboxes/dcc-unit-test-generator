#include <stdio.h>
#include <stdbool.h>
enum ValKind { VAL_INT, VAL_BOOL };
struct Val { enum ValKind kind; union { int integer; bool boolean; }; };
static struct Val val_and(struct Val a, struct Val b) {
    if (a.kind == VAL_BOOL && b.kind == VAL_BOOL)
        return (struct Val){.kind = VAL_BOOL, .boolean = a.boolean && b.boolean};
    return (struct Val){.kind = VAL_INT, .integer = a.integer & b.integer};
}
int main(void) {
    struct Val t = {.kind=VAL_BOOL,.boolean=true};
    struct Val f = {.kind=VAL_BOOL,.boolean=false};
    struct Val r = val_and(t, f);
    printf("c1102 valop=%d,%d\n", (int)r.kind, (int)r.boolean);
    return !(r.kind == VAL_BOOL && !r.boolean);
}
