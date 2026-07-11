#include <stdio.h>

static int split_escaped(const char *s, char out[][8], int cap)
{
    int field, pos, escaped;
    field = 0; pos = 0; escaped = 0;
    while (*s != '\0' && field < cap) {
        if (escaped) { if (pos < 7) out[field][pos++] = *s; escaped = 0; }
        else if (*s == '\\') escaped = 1;
        else if (*s == '|') { out[field][pos] = '\0'; ++field; pos = 0; }
        else if (pos < 7) out[field][pos++] = *s;
        ++s;
    }
    if (escaped || field >= cap) return -1;
    out[field][pos] = '\0';
    return field + 1;
}

int main(void)
{
    char fields[4][8];
    int n, ok;
    n = split_escaped("alpha|b\\|c|d\\\\e", fields, 4);
    ok = n == 3 && fields[1][1] == '|' && fields[2][1] == '\\';
    printf("c8904 escaped=%d,%s,%s\n", n, fields[1], fields[2]);
    return !ok;
}
