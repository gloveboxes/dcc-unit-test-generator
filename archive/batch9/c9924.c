#include <stdio.h>
static void matvec(int rows,const int matrix[rows][3],const int *restrict vector,int *restrict out){for(int r=0;r<rows;++r){out[r]=0;for(int c=0;c<3;++c)out[r]+=matrix[r][c]*vector[c];}}
int main(void){int matrix[3][3]={{1,2,3},{0,1,4},{5,6,0}},vector[3]={2,-1,3},out[3];matvec(3,matrix,vector,out);printf("c9924 matvec=%d,%d,%d\n",out[0],out[1],out[2]);return !(out[0]==9&&out[1]==11&&out[2]==4);}
