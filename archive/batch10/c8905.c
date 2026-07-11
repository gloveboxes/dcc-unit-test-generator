#include <stdio.h>

static int kmp_find(const char *text, const char *pat)
{
    int fail[12], i, j;
    fail[0] = 0;
    for (i = 1, j = 0; pat[i] != '\0'; ++i) {
        while (j > 0 && pat[i] != pat[j]) j = fail[j - 1];
        if (pat[i] == pat[j]) ++j;
        fail[i] = j;
    }
    for (i = 0, j = 0; text[i] != '\0'; ++i) {
        while (j > 0 && text[i] != pat[j]) j = fail[j - 1];
        if (text[i] == pat[j]) ++j;
        if (pat[j] == '\0') return i - j + 1;
    }
    return -1;
}

int main(void)
{
    int first, missing;
    first = kmp_find("ABABACABABACA", "ABABACA");
    missing = kmp_find("CONTROL", "TROLL");
    printf("c8905 kmp=%d,%d\n", first, missing);
    return !(first == 0 && missing == -1);
}
