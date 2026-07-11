#include <stdio.h>
static int occurrences(const char *s,const char *key){int i,j,r=0;for(i=0;s[i];++i){for(j=0;key[j]&&s[i+j]==key[j];++j){ }if(!key[j])++r;}return r;}
int main(void){printf("c8933 occur=%d,%d\n",occurrences("banana","ana"),occurrences("aaaa","aa"));return 0;}
