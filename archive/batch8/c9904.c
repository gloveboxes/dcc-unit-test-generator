#include <stdio.h>
static void prefix_sum(int count, const int input[count], int output[count]) {
    int running = 0; for (int i = 0; i < count; ++i) { running += input[i]; output[i] = running; }
}
int main(void) {
    int input[5] = {2,1,4,3,5}, output[5]; prefix_sum(5, input, output);
    printf("c9904 prefix=%d,%d\n", output[2], output[4]); return !(output[2] == 7 && output[4] == 15);
}
