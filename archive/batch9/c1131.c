#include <stdio.h>
struct Vector3 { union { struct { int x,y,z; }; int component[3]; }; };
static int dot(const struct Vector3 *a,const struct Vector3 *b){int total=0;for(int i=0;i<3;++i)total+=a->component[i]*b->component[i];return total;}
int main(void){struct Vector3 a={.x=2,.y=3,.z=4},b={.component={5,-1,2}};int value=dot(&a,&b);printf("c1131 vector=%d\n",value);return value!=15;}
