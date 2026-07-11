#include <stdio.h>
#include <stdint.h>
static const uint8_t permissions[8]={[0]=0,[1]=1,[2]=2,[3]=3,[4]=4,[5]=5,[6]=6,[7]=7};
static int allowed(unsigned role,unsigned required){return role<8U&&(permissions[role]&required)==required;}
int main(void){int a=allowed(7U,5U),b=allowed(2U,1U);printf("c9908 access=%d,%d\n",a,b);return !(a&&!b);}
