#include <stdio.h>
#include <stdbool.h>
struct Atom {
    enum { ATOM_SYM, ATOM_NUM } kind;
    union {
        int number;
        char symbol[6];
    };
};
static bool atom_eq(const struct Atom *a, const struct Atom *b) {
    if (a->kind != b->kind) return false;
    if (a->kind == ATOM_NUM) return a->number == b->number;
    int i = 0;
    while (a->symbol[i] && b->symbol[i] && a->symbol[i] == b->symbol[i]) i++;
    return a->symbol[i] == b->symbol[i];
}
int main(void) {
    struct Atom n1 = {.kind=ATOM_NUM, .number=42};
    struct Atom n2 = {.kind=ATOM_NUM, .number=42};
    struct Atom s1 = {.kind=ATOM_SYM, .symbol="foo"};
    struct Atom s2 = {.kind=ATOM_SYM, .symbol="bar"};
    bool r1 = atom_eq(&n1, &n2);
    bool r2 = atom_eq(&s1, &s2);
    printf("c1116 atom=%d,%d\n", (int)r1, (int)r2);
    return !(r1 && !r2);
}
