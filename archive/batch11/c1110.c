#include <stdio.h>
#include <stdbool.h>
struct NetAddr {
    union {
        struct { unsigned char a, b, c, d; };
        unsigned char bytes[4];
    };
};
static bool same_subnet(const struct NetAddr *ip, const struct NetAddr *net, const struct NetAddr *mask) {
    for (int i = 0; i < 4; i++)
        if ((ip->bytes[i] & mask->bytes[i]) != (net->bytes[i] & mask->bytes[i]))
            return false;
    return true;
}
int main(void) {
    struct NetAddr ip   = {.a=192,.b=168,.c=1,.d=50};
    struct NetAddr net  = {.a=192,.b=168,.c=1,.d=0};
    struct NetAddr mask = {.a=255,.b=255,.c=255,.d=0};
    struct NetAddr out  = {.a=10,.b=0,.c=0,.d=5};
    bool in = same_subnet(&ip, &net, &mask);
    bool ext = same_subnet(&out, &net, &mask);
    printf("c1110 subnet=%d,%d\n", (int)in, (int)ext);
    return !(in && !ext);
}
