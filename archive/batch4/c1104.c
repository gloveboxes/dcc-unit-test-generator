#include <stdio.h>
enum JobKind{JOB_COPY,JOB_DELETE};
struct Job{enum JobKind kind;union{struct{int source;int target;};int file;};};
int main(void){struct Job copy={JOB_COPY,{.source=2,.target=9}},remove={JOB_DELETE,{.file=7}};printf("c1104 jobs=%d,%d/%d\n",copy.source,copy.target,remove.kind);return 0;}
