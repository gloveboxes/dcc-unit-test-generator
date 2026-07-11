#include <stdio.h>
#include <string.h>

struct Morse { char ch; const char *code; };
static const struct Morse table[4]={{'C',"-.-."},{'P',".--."},{'M',"--"},{'2',"..---"}};
static int units(const char *text)
{
    int i,j,total,len;total=0;
    for(i=0;text[i];++i){
        j=0;
        while(j<4&&table[j].ch!=text[i])++j;
        if(j==4)return -1;len=(int)strlen(table[j].code);while(len--){total+=table[j].code[len]=='-'?3:1;if(len)++total;}if(text[i+1])total+=3;
    }
    return total;
}

int main(void)
{
    int a,b;a=units("CPM");b=units("C2");
    printf("c8923 morse=%d,%d\n",a,b);
    return !(a==35&&b==29);
}
