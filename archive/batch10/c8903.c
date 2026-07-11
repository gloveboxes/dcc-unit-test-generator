#include <stdio.h>

static long restore(const signed char *delta, int n, int first, int *out)
{
    int i;
    long checksum;
    out[0] = first;
    checksum = first;
    for (i = 1; i < n; ++i) {
        out[i] = out[i - 1] + delta[i - 1];
        checksum = checksum * 7L + out[i];
    }
    return checksum;
}

int main(void)
{
    signed char delta[5] = {3,-5,8,-2,1};
    int values[6];
    long check;
    check = restore(delta, 6, 20, values);
    printf("c8903 telemetry=%d,%d,%ld\n", values[2], values[5], check);
    return !(values[2] == 18 && values[5] == 25 && check == 399004L);
}
