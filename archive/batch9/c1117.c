#include <stdio.h>
enum ShapeKind { CIRCLE, BOX };
struct Shape { enum ShapeKind kind; union { int radius; struct { int width,height; }; }; };
static int measure(const struct Shape *shape){return shape->kind==CIRCLE?shape->radius*shape->radius:shape->width*shape->height;}
int main(void){struct Shape shapes[2]={{.kind=CIRCLE,.radius=5},{.kind=BOX,.width=4,.height=7}};int total=measure(&shapes[0])+measure(&shapes[1]);printf("c1117 shapes=%d\n",total);return total!=53;}
