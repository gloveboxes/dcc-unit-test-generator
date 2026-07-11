#include <stdio.h>

struct Duration { long seconds; int millis; };

static void normalize(struct Duration *d)
{
    while (d->millis >= 1000) { ++d->seconds; d->millis -= 1000; }
    while (d->millis < 0) { --d->seconds; d->millis += 1000; }
}
static struct Duration add(struct Duration a, struct Duration b)
{
    struct Duration out;
    out.seconds = a.seconds + b.seconds; out.millis = a.millis + b.millis;
    normalize(&out); return out;
}

int main(void)
{
    struct Duration a = {3599L,850}, b = {2L,375}, result;
    result = add(a,b);
    printf("c8914 duration=%ld.%03d\n", result.seconds, result.millis);
    return !(result.seconds == 3602L && result.millis == 225);
}
