#include <stdio.h>
struct Record{int id;int score;};
static int total_score(const struct Record *records,int count){int total=0,i;for(i=0;i<count;++i)total+=records[i].score;return total;}
int main(void){struct Record records[3]={[0]={101,8},[2]={103,12},[1]={102,10}};printf("c9901 records=%d,%d\n",records[1].id,total_score(records,3));return 0;}
