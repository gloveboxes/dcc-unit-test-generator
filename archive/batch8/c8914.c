#include <stdio.h>

static int parse_csv_row(const char *text, int values[], int capacity)
{
    int count = 0; int value = 0; int have_digit = 0;
    while (1) {
        if (*text >= '0' && *text <= '9') {
            value = value * 10 + (*text - '0'); have_digit = 1;
        } else if (*text == ',' || *text == '\0') {
            if (!have_digit || count == capacity) return -1;
            values[count++] = value; value = 0; have_digit = 0;
            if (*text == '\0') break;
        } else return -1;
        ++text;
    }
    return count;
}

int main(void)
{
    int values[4]; int count = parse_csv_row("12,7,305", values, 4);
    printf("c8914 csv=%d,%d\n", count, values[2]);
    return !(count == 3 && values[2] == 305);
}
