#include <stdio.h>
#include <stdbool.h>
struct Config { int baud; int retries; bool echo; };
static bool valid(struct Config config){return config.baud>=300&&config.baud<=19200&&config.retries>=0&&config.retries<=5;}
int main(void){struct Config config={.echo=true,.retries=3,.baud=9600};printf("c9909 config=%d,%d\n",(int)valid(config),(int)config.echo);return !(valid(config)&&config.echo);}
