#include <stdio.h>
static void format_time(long seconds, char output[9]) { int h=(int)(seconds/3600L), m=(int)((seconds/60L)%60L), s=(int)(seconds%60L); sprintf(output,"%02d:%02d:%02d",h,m,s); }
int main(void) { char output[9]; format_time(45296L,output); printf("c9920 time=%s\n",output); return !(output[0]=='1' && output[6]=='5'); }
