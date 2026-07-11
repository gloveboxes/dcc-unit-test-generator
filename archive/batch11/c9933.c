#include <stdio.h>
#include <stdbool.h>
static bool match(const char *pattern, const char *text) {
    if (!*pattern) return !*text;
    if (pattern[1] == '*') {
        if (match(pattern + 2, text)) return true;
        while (*text && (*pattern == '.' || *text == *pattern))
            if (match(pattern + 2, ++text)) return true;
        return false;
    }
    if (*text && (*pattern == '.' || *text == *pattern))
        return match(pattern + 1, text + 1);
    return false;
}
int main(void) {
    bool a = match("a*b", "aaab");
    bool b = match("a.c", "abc");
    bool c = match("a*b", "aac");
    printf("c9933 regex=%d,%d,%d\n", (int)a, (int)b, (int)c);
    return !(a && b && !c);
}
