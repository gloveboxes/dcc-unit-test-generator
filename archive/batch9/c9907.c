#include <stdio.h>
static int sum_fields(const char *line){int sum=0;while(*line){int value=0;while(*line>='0'&&*line<='9')value=value*10+(*line++-'0');sum+=value;if(*line==',')++line;else if(*line) return -1;}return sum;}
int main(void){int value=sum_fields("12,7,31");printf("c9907 fields=%d\n",value);return value!=50;}
