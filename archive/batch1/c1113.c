#include <stdio.h>

struct Version { union { unsigned value; struct { unsigned major:4; unsigned minor:4; unsigned patch:8; }; }; };
int main(void)
{
    struct Version version = {.major = 2, .minor = 7, .patch = 15};
    printf("c1113 version=%u.%u.%u\n", version.major, version.minor, version.patch);
    return 0;
}
