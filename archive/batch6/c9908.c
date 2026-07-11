#include <stdio.h>
struct Entry{int key;int value;};
static const struct Entry entries[3]={[2]={30,300},[0]={10,100},[1]={20,200}};
int main(void){printf("c9908 table=%d,%d\n",entries[0].value,entries[2].key);return 0;}
