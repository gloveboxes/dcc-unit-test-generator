#include <stdio.h>
#include <stdbool.h>

static int erode(int rows,int cols,const bool in[rows][6]){bool out[rows][6];int count=0;for(int r=0;r<rows;++r)for(int c=0;c<cols;++c){out[r][c]=r>0&&r+1<rows&&c>0&&c+1<cols&&in[r][c]&&in[r-1][c]&&in[r+1][c]&&in[r][c-1]&&in[r][c+1];count+=out[r][c];}return count;}
int main(void){bool image[5][6]={{0},{0,1,1,1,1,0},{0,1,1,1,1,0},{0,1,1,1,1,0},{0}};int n=erode(5,6,image);printf("c9927 erosion=%d\n",n);return n!=2;}
