#include <stdio.h>

static int encode_runs(const char *input, char output[], int capacity)
{
    int read = 0; int written = 0; int count;
    while (input[read] != '\0') {
        count = 1;
        while (input[read + count] == input[read] && count < 9) ++count;
        if (written + 2 >= capacity) return 0;
        output[written++] = input[read];
        output[written++] = (char)('0' + count);
        read += count;
    }
    output[written] = '\0'; return written;
}

int main(void)
{
    char output[16]; int length = encode_runs("AAABBCCCC", output, 16);
    printf("c8913 rle=%d,%s\n", length, output);
    return !(length == 6 && output[0] == 'A' && output[5] == '4');
}
