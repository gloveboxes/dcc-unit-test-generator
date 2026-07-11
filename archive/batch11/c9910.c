#include <stdio.h>
#include <stdint.h>
enum Month { JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC };
static const int days_in[13] = {
    [JAN]=31,[FEB]=28,[MAR]=31,[APR]=30,[MAY]=31,[JUN]=30,
    [JUL]=31,[AUG]=31,[SEP]=30,[OCT]=31,[NOV]=30,[DEC]=31
};
int main(void) {
    int total = 0;
    for (int m = JAN; m <= DEC; m++) total += days_in[m];
    printf("c9910 year=%d,%d\n", total, days_in[FEB]);
    return !(total == 365 && days_in[FEB] == 28);
}
