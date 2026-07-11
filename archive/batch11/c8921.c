#include <stdio.h>
static int celsius_to_f(int c){return c*9/5+32;}
static int fahrenheit_to_c(int f){return (f-32)*5/9;}
int main(void){int boil=celsius_to_f(100),freeze=celsius_to_f(0),back=fahrenheit_to_c(212);printf("c8921 temp=%d,%d,%d\n",boil,freeze,back);return !(boil==212&&freeze==32&&back==100);}
