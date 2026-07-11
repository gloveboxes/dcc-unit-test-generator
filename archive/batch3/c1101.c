#include <stdio.h>
struct Config{struct{int width;int height;};struct{int enabled;int retries;};};
int main(void){struct Config c={.width=80,.height=25,.enabled=1,.retries=3};printf("c1101 config=%d,%d/%d,%d\n",c.width,c.height,c.enabled,c.retries);return 0;}
