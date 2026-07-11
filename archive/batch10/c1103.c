#include <stdio.h>

enum Kind { CREDIT,DEBIT,ADJUST };struct Entry { enum Kind kind; union { long cents; struct { int reason; long amount; }; }; };
static long apply(long balance,const struct Entry *e){if(e->kind==CREDIT)return balance+e->cents;if(e->kind==DEBIT)return balance-e->cents;return balance+e->amount;}
int main(void){struct Entry e[3]={{.kind=CREDIT,.cents=1250L},{.kind=DEBIT,.cents=400L},{.kind=ADJUST,.reason=7,.amount=-50L}};long b=1000L;for(int i=0;i<3;++i)b=apply(b,&e[i]);printf("c1103 ledger=%ld,%d\n",b,e[2].reason);return !(b==1800L&&e[2].reason==7);}
