#include <stdio.h>
struct Config{int width;int height;int enabled;};
int main(void){struct Config c={.height=25,.width=80,.enabled=1};printf("c9901 config=%d,%d,%d\n",c.width,c.height,c.enabled);return 0;}
