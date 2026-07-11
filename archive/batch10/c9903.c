#include <stdio.h>
#include <stdint.h>

static const int8_t keypad[16]={[0]=-1,[1]=7,[2]=8,[3]=9,[5]=4,[6]=5,[7]=6,[9]=1,[10]=2,[11]=3,[14]=0,[15]=10};
static int decode(const uint8_t *scan,int n){int value=0;for(int i=0;i<n;++i){int key=keypad[scan[i]&15U];if(key<0||key>9)return -1;value=value*10+key;}return value;}
int main(void){uint8_t ok[4]={9,10,11,14},bad[2]={1,0};int a=decode(ok,4),b=decode(bad,2);printf("c9903 keypad=%d,%d\n",a,b);return !(a==1230&&b==-1);}
