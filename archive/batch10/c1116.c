#include <stdio.h>

enum JournalKind { START,PROGRESS,FINISH };struct Journal { int sequence;enum JournalKind kind;union { struct { int job,owner; };struct { int completed,total; };struct { int status,checksum; }; }; };
static int score(const struct Journal *e){if(e->kind==START)return e->job+e->owner;if(e->kind==PROGRESS)return e->completed*100/e->total;return e->status?0:e->checksum;}
int main(void){struct Journal log[3]={{.sequence=1,.kind=START,.job=12,.owner=4},{.sequence=2,.kind=PROGRESS,.completed=7,.total=10},{.sequence=3,.kind=FINISH,.status=0,.checksum=55}};int sum=0;for(int i=0;i<3;++i)sum+=score(&log[i]);printf("c1116 journal=%d,%d\n",sum,log[1].completed);return !(sum==141&&log[1].completed==7);}
