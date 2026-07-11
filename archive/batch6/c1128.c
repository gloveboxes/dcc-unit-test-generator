#include <stdio.h>
struct Version{unsigned major:4;unsigned minor:4;};
static int compare(struct Version a,struct Version b){return a.major!=b.major?a.major-b.major:a.minor-b.minor;}
int main(void){struct Version a={2,3},b={2,1};printf("c1128 version=%d\n",compare(a,b));return 0;}
