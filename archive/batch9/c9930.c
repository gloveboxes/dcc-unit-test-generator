#include <stdio.h>
#include <stdbool.h>
static int palindrome_length(int count,const char text[count]){bool table[count][16];int best=1;for(int i=0;i<count;++i)table[i][i]=true;for(int length=2;length<=count;++length)for(int left=0;left+length<=count;++left){int right=left+length-1;table[left][right]=text[left]==text[right]&&(length==2||table[left+1][right-1]);if(table[left][right])best=length;}return best;}
int main(void){char text[]="BANANAS";int length=palindrome_length(7,text);printf("c9930 palindrome=%d\n",length);return length!=5;}
