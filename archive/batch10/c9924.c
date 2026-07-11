#include <stdio.h>
#include <stdbool.h>

struct Access { unsigned owner:3;unsigned group:3;unsigned other:3;unsigned locked:1; };
static bool allowed(struct Access a,int class,unsigned need){unsigned bits=class==0?a.owner:class==1?a.group:a.other;return !a.locked&&(bits&need)==need;}
int main(void){struct Access file={.owner=7,.group=5,.other=1,.locked=0};bool a=allowed(file,1,5),b=allowed(file,2,2);file.locked=1;bool c=allowed(file,0,4);printf("c9924 access=%d,%d,%d\n",(int)a,(int)b,(int)c);return !(a&&!b&&!c);}
