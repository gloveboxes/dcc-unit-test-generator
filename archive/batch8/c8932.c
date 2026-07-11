#include <stdio.h>

static int normalize_path(const char *input, char output[], int capacity)
{
    int written = 0; char previous = '\0';
    while (*input) {
        if (!(*input == '/' && previous == '/')) {
            if (written + 1 >= capacity) return 0;
            output[written++] = *input; previous = *input;
        }
        ++input;
    }
    if (written > 1 && output[written - 1] == '/') --written;
    output[written] = '\0'; return written;
}

int main(void)
{
    char output[16]; int length = normalize_path("//usr///bin/", output, 16);
    printf("c8932 path=%d,%s\n", length, output);
    return !(length == 8 && output[5] == 'b');
}
