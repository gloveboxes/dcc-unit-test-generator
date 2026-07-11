#include <stdio.h>
#include <stdbool.h>

enum ColumnKind { INTEGER,BOOLEAN,TEXT };struct Column { enum ColumnKind kind;union { int integer;bool boolean;struct { char text[6];int length; }; }; };
static int weight(const struct Column *c){if(c->kind==INTEGER)return c->integer;if(c->kind==BOOLEAN)return c->boolean?10:0;return c->length+(unsigned char)c->text[0];}
int main(void){struct Column row[3]={{.kind=INTEGER,.integer=8},{.kind=BOOLEAN,.boolean=true},{.kind=TEXT,.text="CPM",.length=3}};int total=0;for(int i=0;i<3;++i)total+=weight(&row[i]);printf("c1121 columns=%d,%c\n",total,row[2].text[2]);return !(total==88&&row[2].text[2]=='M');}
