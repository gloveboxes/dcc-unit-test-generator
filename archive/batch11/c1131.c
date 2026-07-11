#include <stdio.h>
#include <stdbool.h>
struct Variant {
    enum { V_NONE, V_INT, V_PAIR } type;
    union {
        int scalar;
        struct { int first; int second; };
    };
};
static int variant_value(const struct Variant *v) {
    if (v->type == V_INT)  return v->scalar;
    if (v->type == V_PAIR) return v->first + v->second;
    return 0;
}
int main(void) {
    struct Variant a = {.type=V_INT, .scalar=42};
    struct Variant b = {.type=V_PAIR, .first=18, .second=24};
    struct Variant c = {.type=V_NONE};
    printf("c1131 variant=%d,%d,%d\n", variant_value(&a), variant_value(&b), variant_value(&c));
    return !(variant_value(&a)==42 && variant_value(&b)==42 && variant_value(&c)==0);
}
