#include <stdio.h>
#define ARENA_SIZE 32
struct Arena{unsigned char data[ARENA_SIZE];int used;};
static void *allocate(struct Arena *arena,int size){void *result;if(size<0||arena->used+size>ARENA_SIZE)return 0;result=&arena->data[arena->used];arena->used+=size;return result;}
int main(void){struct Arena arena;void *a,*b;arena.used=0;a=allocate(&arena,10);b=allocate(&arena,24);printf("c8933 arena=%d,%d\n",a!=0,b==0);return !(a!=0&&b==0&&arena.used==10);}
