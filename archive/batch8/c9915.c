#include <stdio.h>
static void transform(int count, const int * restrict input, int * restrict output) {
    for (int i=0;i<count;++i) output[i]=input[i]*input[i]-input[i];
}
int main(void) { int input[4]={1,2,3,4}, output[4]; transform(4,input,output); printf("c9915 transform=%d,%d\n",output[1],output[3]); return !(output[1]==2 && output[3]==12); }
