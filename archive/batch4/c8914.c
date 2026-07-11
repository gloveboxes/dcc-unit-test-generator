#include <stdio.h>
static int count_words(const char *s){int in_word=0,count=0,i;for(i=0;s[i];++i){if(s[i]!=' '&&!in_word){++count;in_word=1;}else if(s[i]==' ')in_word=0;}return count;}
int main(void){printf("c8914 words=%d,%d\n",count_words("one two three"),count_words("  alpha  beta"));return 0;}
