#include <stdio.h>

static int transpose_score(int rows,int cols,const int input[rows][3]){int output[cols][2];int score=0;for(int r=0;r<rows;++r)for(int c=0;c<cols;++c)output[c][r]=input[r][c];for(int c=0;c<cols;++c)for(int r=0;r<rows;++r)score=score*3+output[c][r];return score;}
int main(void){int grid[2][3]={{1,2,0},{2,1,2}};int score=transpose_score(2,3,grid);printf("c9907 transpose=%d\n",score);return score!=470;}
