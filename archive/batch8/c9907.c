#include <stdio.h>
#include <stdbool.h>
static bool valid_identifier(const char *text) {
    if (!((*text >= 'A' && *text <= 'Z') || (*text >= 'a' && *text <= 'z'))) return false;
    for (++text; *text; ++text) if (!((*text >= 'A' && *text <= 'Z') || (*text >= 'a' && *text <= 'z') || (*text >= '0' && *text <= '9'))) return false;
    return true;
}
int main(void) { bool a = valid_identifier("item42"), b = valid_identifier("42item"); printf("c9907 ident=%d,%d\n", (int)a, (int)b); return !(a && !b); }
