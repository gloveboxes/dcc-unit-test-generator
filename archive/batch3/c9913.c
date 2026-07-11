#include <stdio.h>
int main(void){char text[32];int n;sprintf(text,"id=%d hex=%X",27,27);n=(int)text[2]+(int)text[9];printf("c9913 format=%s/%d\n",text,n);return 0;}
