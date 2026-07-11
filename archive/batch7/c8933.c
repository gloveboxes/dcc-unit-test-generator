#include <stdio.h>
static int julian(int y,int m,int d){return (1461*(y+4800+(m-14)/12))/4+(367*(m-2-12*((m-14)/12)))/12-3*((y+4900+(m-14)/12)/100)/4+d-32075;}
int main(void){printf("c8933 julian=%d\n",julian(2026,7,10)-julian(2026,1,1));return 0;}
