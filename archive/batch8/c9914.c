#include <stdio.h>
static void moving_sum(int count, const int input[count], int window, int output[count]) {
    int sum = 0; for (int i = 0; i < count; ++i) { sum += input[i]; if (i >= window) sum -= input[i-window]; output[i] = sum; }
}
int main(void) {
    int input[5]={1,3,5,7,9}, output[5]; moving_sum(5,input,3,output);
    printf("c9914 window=%d,%d\n",output[2],output[4]); return !(output[2]==9 && output[4]==21);
}
