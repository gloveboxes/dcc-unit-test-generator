#include <stdio.h>

static int token_lengths(const char *text, int lengths[], int capacity)
{
    int count = 0; int length;
    while (*text) {
        while (*text == ' ') ++text;
        if (!*text) break;
        if (count == capacity) return -1;
        length = 0; while (text[length] && text[length] != ' ') ++length;
        lengths[count++] = length; text += length;
    }
    return count;
}

int main(void)
{
    int lengths[4]; int count = token_lengths("  write clear code ", lengths, 4);
    printf("c8931 tokens=%d,%d,%d\n", count, lengths[0], lengths[2]);
    return !(count == 3 && lengths[0] == 5 && lengths[2] == 4);
}
