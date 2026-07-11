#include <stdio.h>
struct ShapeRec{int shape_id;union{struct{unsigned char w;unsigned char h;} rect;unsigned char radius;};};
int main(void){struct ShapeRec s={2,{.radius=10}};printf("c1113 rec=%d,%d\n",s.shape_id,s.radius);return 0;}
