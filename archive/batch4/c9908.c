#include <stdio.h>
struct Matrix{int values[2][2];};
static struct Matrix multiply(struct Matrix a,struct Matrix b){struct Matrix r={{{0,0},{0,0}}};int i,j,k;for(i=0;i<2;++i)for(j=0;j<2;++j)for(k=0;k<2;++k)r.values[i][j]+=a.values[i][k]*b.values[k][j];return r;}
int main(void){struct Matrix a={{{1,2},{3,4}}},b={{{2,0},{1,2}}},r;r=multiply(a,b);printf("c9908 matrix=%d,%d/%d,%d\n",r.values[0][0],r.values[0][1],r.values[1][0],r.values[1][1]);return 0;}
