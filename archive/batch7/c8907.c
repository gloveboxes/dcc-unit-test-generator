#include <stdio.h>
static int is_palindrome(int n){int r=0,x=n;while(x){r=r*10+x%10;x/=10;}return r==n;}
int main(void){printf("c8907 pal=%d,%d\n",is_palindrome(12321),is_palindrome(1234));return 0;}
