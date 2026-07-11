#include <stdio.h>
enum InputKind { KEY_INPUT, AXIS_INPUT };
struct Input { enum InputKind kind; union { struct { char key; int down; }; struct { int axis,value; }; }; };
static int magnitude(const struct Input *input){if(input->kind==KEY_INPUT)return input->down?1:0;return input->value<0?-input->value:input->value;}
int main(void){struct Input inputs[2]={{.kind=KEY_INPUT,.key='A',.down=1},{.kind=AXIS_INPUT,.axis=0,.value=-73}};int total=magnitude(&inputs[0])+magnitude(&inputs[1]);printf("c1129 input=%d,%c\n",total,inputs[0].key);return !(total==74&&inputs[0].key=='A');}
