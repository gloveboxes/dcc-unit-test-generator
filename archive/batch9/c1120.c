#include <stdio.h>
#include <stdbool.h>
struct Result { bool ok; union { int value; int error; }; };
static struct Result divide(int a,int b){struct Result result;if(b==0){result.ok=false;result.error=-1;}else{result.ok=true;result.value=a/b;}return result;}
int main(void){struct Result a=divide(84,2),b=divide(3,0);printf("c1120 result=%d,%d,%d\n",(int)a.ok,a.value,b.error);return !(a.ok&&a.value==42&&!b.ok&&b.error==-1);}
