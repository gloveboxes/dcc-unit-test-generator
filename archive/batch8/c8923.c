#include <stdio.h>

static void rotate_right(int values[], int count, int places)
{
    int copy[8]; int i;
    places %= count;
    for (i = 0; i < count; ++i) copy[(i + places) % count] = values[i];
    for (i = 0; i < count; ++i) values[i] = copy[i];
}

int main(void)
{
    int values[6] = {1,2,3,4,5,6};
    rotate_right(values, 6, 2);
    printf("c8923 rotate=%d,%d,%d\n", values[0], values[2], values[5]);
    return !(values[0] == 5 && values[2] == 1 && values[5] == 4);
}
