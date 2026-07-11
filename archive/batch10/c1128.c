#include <stdio.h>
#include <stdbool.h>

enum LiteralKind { INTEGER,CHARACTER,IDENTIFIER };struct Literal { enum LiteralKind kind;union { int integer;char character;struct { char name[8];int length; }; }; };
static int classify(const struct Literal *l){if(l->kind==INTEGER)return l->integer%10;if(l->kind==CHARACTER)return (unsigned char)l->character;return l->length+(unsigned char)l->name[0];}
int main(void){struct Literal v[3]={{.kind=INTEGER,.integer=42},{.kind=CHARACTER,.character='+'},{.kind=IDENTIFIER,.name="PORT",.length=4}};int total=0;for(int i=0;i<3;++i)total+=classify(&v[i]);printf("c1128 literals=%d,%c\n",total,v[2].name[3]);return !(total==129&&v[2].name[3]=='T');}
