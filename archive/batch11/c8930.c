#include <stdio.h>
static int is_palindrome_num(long n){long rev=0;long orig=n;if(n<0)return 0;while(n>0){rev=rev*10+n%10;n/=10;}return rev==orig;}
int main(void){int a=is_palindrome_num(12321L),b=is_palindrome_num(12345L);printf("c8930 palnum=%d,%d\n",a,b);return !(a&&!b);}
