#include <stdio.h>

enum { OK = 200, NOTFOUND = 404, BUSY = 503 };
static const char *labels[600] = {[OK] = "ok", [NOTFOUND] = "missing", [BUSY] = "busy"};
int main(void)
{
    printf("c9901 status=%s/%s/%s\n", labels[OK], labels[NOTFOUND], labels[BUSY]);
    return 0;
}
